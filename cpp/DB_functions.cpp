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
#include "headers/onlineStore.h"
#include <list>
#include <cctype>
//#include "libssl-1_1-x64.dll"
using namespace std;
using namespace sql;


//for demonstration only. never save your password in the code!
const string server = "sql8.freemysqlhosting.net";
const string username = "sql8612103";
const string password = "m624G5CJxr";

class functions {
	static Connection *con;

public:
	    static void connectsql() {
		sql::Driver* driver;
		sql::Statement* stmt;
		sql::PreparedStatement* pstmt;
		sql::ResultSet* res;
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
protected:
	        static ResultSet * select (string tableName, string condition) {
		    static ResultSet* rs = NULL;
			try {
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
protected:
	        static list<Product> getProductsInCart(int cartId) {
				list<Product> productList ;
				ResultSet* productsInCartSet = select(ProductInCart::tableName, "cartId = " + cartId);
				try {
					while (productsInCartSet->next()) {
						ResultSet* productSet = select(Product::tableName, "id = " + productsInCartSet->getInt("id"));
						if (productSet->next())
							productList.push_back(
								 Product(
									 productSet->getString("name"),
									productSet->getString("description"),
									 productSet->getDouble("price"),
									// productSet->getInt("id"),
									productSet->getInt("quantity"),
								productSet->getDouble("userRating")
									
									
									
								)
							);
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
protected:
	static boolean isProductInCart(int cartId, int productId) {
				try {
					string ss = "cartId = " +to_string (cartId)+ "and productId = " + to_string (productId);// maybe error
					return select("ProductInCart",ss)->next(); 
				}
				catch (sql::SQLException e)
				{
					cout << "Could not connect to server. Error message: " << e.what() << endl;
					system("pause");
					exit(1);
				}
				return false;
			}
protected:
	static boolean addProductInCart(int cartId, int productId, int count) {
		try {
			if (!isProductInCart(cartId, productId)) {
				string insertSql = "INSERT INTO " + ProductInCart::tableName + " (cartId, productId, count)" +
					" VALUES (?, ?, ?)";

				PreparedStatement* pstmt = con->prepareStatement(insertSql);

				pstmt->setInt(1, cartId);
				pstmt->setInt(2, productId);
				pstmt->setInt(3, count);

				int numRowsAffected = pstmt->executeUpdate();
				if (numRowsAffected > 0) return true;

			}
			else return true;
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}
		return true;
	}
	protected:
		static boolean removeFromCart(int cartId, int productId) {
			try {
			PreparedStatement* pstmt = con->prepareStatement("DELETE FROM " + ProductInCart::tableName + " WHERE cartId = ? AND productId = ?;");
			pstmt ->setInt(1, cartId);
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
		protected:
			static User* authenticateUser(User user) {
				User* result;
				try {
					Statement* stmt = con->createStatement();
					ResultSet* rs = stmt->executeQuery(
						"select * from " + User::tableName
						+ " WHERE email=" + user.getEmail() + " AND pass=" + user.getPass());

					if (rs->next()) {
						result = new User(
							rs->getString("Name"),
							rs->getString("Pass"),
							rs->getString("Email")
						);
						result->setId(rs->getInt("id"));
						result->setCartId(rs->getInt("cartId"));

						return result;
					}
				}
				catch (sql::SQLException e)
				{
					cout << "Could not connect to server. Error message: " << e.what() << endl;
					system("pause");
					exit(1);
				}
				return NULL;
			}
			protected:
				static boolean createUser(User user) {

				try {
					// Create Cart
					string insertSql = "INSERT INTO " + Cart::tableName + " ()" +
						" VALUES ()";

					PreparedStatement* pstmt = con->prepareStatement(insertSql, Statement->RETURN_GENERATED_KEYS);

					int cartId = 0;

					if (pstmt->executeUpdate() > 0) {
						ResultSet *rs = pstmt->getGeneratedKeys();
						if (rs->next()) {
							cartId = rs->getInt(1);
						}
					}

					if (cartId == 0) return false;

					// Create User
					insertSql = "INSERT INTO " + User::tableName + " (name, pass, email, userAdress, creditCardNumber, cartId)" +
						" VALUES (?, ?, ?, ?, ?, ?)";

					pstmt =con->prepareStatement(insertSql, Statement->RETURN_GENERATED_KEYS);

					pstmt->setString(1, user.getName());
					pstmt->setString(2, user.getPass());
					pstmt->setString(3, user.getEmail());
					pstmt->setString(4, user.getAddress());
					pstmt->setString(5, user.getCreditCardNumber());
					pstmt->setInt(6, cartId);

					int numRowsAffected = pstmt->executeUpdate();
					if (numRowsAffected > 0) {
						ResultSet *rs = pstmt->getGeneratedKeys();
						if (rs->next()) {
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

		
		protected:
			static string savePayment(Payment payment) {
			ResultSet* userSet = select(User::tableName, "id = " + payment.getUserId());
			try {
				if (userSet->next()) {
					list<Product> products = getProductsInCart(userSet->getInt("cartId"));
					if (!(products.size() > 0)) return "No products in cart!";

					string insertSql = "INSERT INTO " + Payment::tableName + " (value, userId)" +
						" VALUES (?, ?)";

					PreparedStatement* pstmt =con->prepareStatement(insertSql);

					pstmt->setDouble(1, payment.getValue());
					pstmt->setInt(2, payment.getUserId());

					int numRowsAffected = pstmt->executeUpdate();
					if (numRowsAffected > 0) {
						return "Payment processed successfully";
					}
				}
				else return "User does not exist!";
			}
			catch (sql::SQLException e)
			{
				cout << "Could not connect to server. Error message: " << e.what() << endl;
				system("pause");
				exit(1);
			}
			return "Unknown Error!";
		}
			public:
				static void closeConnection() {
				try {
					con->close();

				}
				catch (sql::SQLException e)
				{
					cout << "Could not connect to server. Error message: " << e.what() << endl;
					system("pause");
					exit(1);
				}
			}



};
int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	

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
	//cout << "3abood hacker te2eel"; 

	////please create database "quickstartdb" ahead of time


	pstmt = con->prepareStatement("SELECT * FROM Products;");

	sql::ResultSet *result = pstmt->executeQuery();
	
	
	//cout << "Finished dropping table (if existed)" << endl;
	//stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
	//cout << "Finished creating table" << endl;
	//delete stmt;

	//pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
	//pstmt->setString(1, "banana");
	//pstmt->setInt(2, 150);
	//pstmt->execute();
	//cout << "One row inserted." << endl;

	//pstmt->setString(1, "orange");
	//pstmt->setInt(2, 154);
	//pstmt->execute();
	//cout << "One row inserted." << endl;

	//pstmt->setString(1, "apple");
	//pstmt->setInt(2, 100);
	//pstmt->execute();
	//cout << "One row inserted." << endl;

	//delete pstmt;
	//delete con;
	//system("pause");
	return 0;
}