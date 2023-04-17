#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <sql.h>
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include <string>
#include "onlineStore.h"
#include <list>
#include <vector>
#include <cctype>
// #include "libssl-1_1-x64.dll"
using namespace std;
using namespace sql;

// for demonstration only. never save your password in the code!
const string server = "sql8.freemysqlhosting.net";
const string username = "sql8613256";
const string password = "hwIw3Fjflu";

class functions
{
	static Connection *con;

public:
	static void connectsql()
	{
		sql::Driver *driver;
		sql::Statement *stmt;
		sql::PreparedStatement *pstmt;
		sql::ResultSet *res;
		try
		{
			driver = get_driver_instance();
			con = driver->connect(server, username, password);
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
	}
	static void closeConnection()
	{
		try
		{
			con->close();
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
	}

protected:
	static ResultSet *select(string tableName, string condition)
	{
		static ResultSet *rs = NULL;
		try
		{
			Statement *stmt = con->createStatement();
			rs = stmt->executeQuery("select * from " + tableName + ((condition != NULL) ? "WHERE " + condition : ""));
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return rs;
	}

	static ResultSet *getLastCreatedId(string tableName)
	{
		static ResultSet *rs = NULL;
		try
		{
			Statement *stmt = con->createStatement();
			rs = stmt->executeQuery("select id from " + tableName + "ORDER BY id DESC FETCH FIRST 1 ROW ONLY;");
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return rs;
	}

	static vector<Product> getProductsInCart(int cartId)
	{
		vector<Product> productList;
		ResultSet *productsInCartSet = select(ProductInCart::tableName, "cartId = " + cartId);
		try
		{
			while (productsInCartSet->next())
			{
				ResultSet *productSet = select(Product::tableName, "id = " + productsInCartSet->getInt("id"));
				if (productSet->next())
					productList.push_back(
						Product(
							productSet->getInt("id"),
							productSet->getString("name"),
							productSet->getString("description"),
							productSet->getDouble("price"),
							// productSet->getInt("id"),
							productSet->getInt("quantity"),
							productSet->getDouble("userRating")

								));
			}
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}

		return productList;
	}

	static boolean isProductInCart(int cartId, int productId)
	{
		try
		{
			string ss = "cartId = " + to_string(cartId) + "and productId = " + to_string(productId); // maybe error
			return select("ProductInCart", ss)->next();
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return false;
	}

	static boolean addProductInCart(int cartId, int productId, int count)
	{
		try
		{
			if (!isProductInCart(cartId, productId))
			{
				string insertSql = "INSERT INTO " + ProductInCart::tableName + " (cartId, productId, count)" +
								   " VALUES (?, ?, ?)";

				PreparedStatement *pstmt = con->prepareStatement(insertSql);

				pstmt->setInt(1, cartId);
				pstmt->setInt(2, productId);
				pstmt->setInt(3, count);

				int numRowsAffected = pstmt->executeUpdate();
				if (numRowsAffected > 0)
					return true;
			}
			else
				return true;
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return true;
	}

	static boolean removeFromCart(int cartId, int productId)
	{
		try
		{
			PreparedStatement *pstmt = con->prepareStatement("DELETE FROM " + ProductInCart::tableName + " WHERE cartId = ? AND productId = ?;");
			pstmt->setInt(1, cartId);
			pstmt->setInt(2, productId);

			return pstmt->executeUpdate() > 0;
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return false;
	}

	public:static vector<Product> getProductList()
	{

		vector<Product> productList;
		ResultSet *rs = select(Product::tableName, NULL);
		try
		{
			while (rs->next())
			{
				productList.push_back(
					Product(
						rs->getInt("id"),
						rs->getString("name"),
						rs->getString("description"),
						rs->getDouble("price"),
						rs->getInt("quantity"),
						rs->getDouble("userRating")));
			}
		}
		catch (SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}

		return productList;
	}

	protected:
		static RegisteredUser authenticateUser(UnRegisteredUser user);

	static boolean createUser(UnRegisteredUser user)
	{

		try
		{
			// Create Cart
			string insertSql = "INSERT INTO " + Cart::tableName + " ()" +
							   " VALUES ()";

			PreparedStatement *pstmt = con->prepareStatement(insertSql);

			int cartId = 0;

			if (pstmt->executeUpdate() > 0)
			{
				ResultSet *rs = getLastCreatedId(Cart::tableName);
				if (rs->next())
				{
					cartId = rs->getInt(1);
				}
			}

			if (cartId == 0)
				return false;

			// Create User
			insertSql = "INSERT INTO " + User::tableName + " (name, pass, email, userAdress, creditCardNumber, cartId)" +
						" VALUES (?, ?, ?, ?, ?, ?)";

			pstmt = con->prepareStatement(insertSql);

			pstmt->setString(1, user.getName());
			pstmt->setString(2, user.getPass());
			pstmt->setString(3, user.getEmail());
			pstmt->setString(4, user.getAddress());
			pstmt->setString(5, user.getCreditCardNumber());
			pstmt->setInt(6, cartId);

			int numRowsAffected = pstmt->executeUpdate();
			if (numRowsAffected > 0)
			{
				ResultSet *rs = getLastCreatedId(User::tableName);
				if (rs->next())
				{
					user.setId(rs->getInt(1));
				}
				return true;
			}
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return false;
	}

	static string savePayment(Payment payment)
	{
		ResultSet *userSet = select(User::tableName, "id = " + payment.getUserId());
		try
		{
			if (userSet->next())
			{
				vector<Product> products = getProductsInCart(userSet->getInt("cartId"));
				if (!(products.size() > 0))
					return "No products in cart!";

				string insertSql = "INSERT INTO " + Payment::tableName + " (value, userId)" +
								   " VALUES (?, ?)";

				PreparedStatement *pstmt = con->prepareStatement(insertSql);

				pstmt->setDouble(1, payment.getValue());
				pstmt->setInt(2, payment.getUserId());

				int numRowsAffected = pstmt->executeUpdate();
				if (numRowsAffected > 0)
				{
					return "Payment processed successfully";
				}
			}
			else
				return "User does not exist!";
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return "Unknown Error!";
	}
};

RegisteredUser functions::authenticateUser(UnRegisteredUser user)
{
	RegisteredUser result;
	try
	{
		Statement *stmt = con->createStatement();
		ResultSet *rs = stmt->executeQuery(
			"select * from " + User::tableName + " WHERE email='" + user.getEmail() + "' AND pass='" + user.getPass() + "'");

		if (rs->next())
		{
			result = RegisteredUser(
				rs->getString("Name"),
				rs->getString("Pass"),
				rs->getString("Email"));
			result.setId(rs->getInt("id"));
			result.setCartId(rs->getInt("cartId"));

			return result;
		}
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}