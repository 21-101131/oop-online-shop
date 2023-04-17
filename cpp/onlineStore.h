#pragma once
#ifndef ONLINESTORE_H
#define ONLINESTORE_H

// #ifndef DB_FUNCTIONS_H
// #define DB_FUNCTIONS_H

#include <iostream>
#include <windows.h>
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include <string>
#include <vector>

using namespace std;
using namespace sql;

// for demonstration only. never save your password in the code!
//const string server = "sql8.freemysqlhosting.net";
// const string username = "sql8613256";
// const string password = "hwIw3Fjflu";

class functions
{
    static Connection* con;

public:
    static void connectsql();
    static void closeConnection();

	template<typename T>
    static vector<T> getProductList();

protected:
    static ResultSet* select(string tableName, string condition);
    static ResultSet* getLastCreatedId(string tableName);

	template<typename T>
    static vector<T> getProductsInCart(int cartId);

    static bool isProductInCart(int cartId, int productId);
    static bool addProductInCart(int cartId, int productId, int count);
    static bool removeFromCart(int cartId, int productId);

	template<typename T>
    static bool createUser(T user);

	template<typename T>
    static string savePayment(T payment);

	template<typename R, typename U>
    static R authenticateUser(U user);
};

//#endif // DB_FUNCTIONS_H

class Product : public functions
{
	int id;
	string name;
	string descreiption;
	double price;
	int quantity;
	float userRating;

public:
	static string tableName;

public:
	Product();
	Product(int id, string nameproduct, string Descreiption, double Price, int Quantity, float UserRating);
	virtual double getPrice();
	virtual string getName();
	virtual int getId();
	virtual string getDescription();
	virtual int getQuantity();
	virtual float getUserRating();
	virtual void setPrice(double price);
	virtual void setName(string name);
	virtual void setDescription(string description);
	virtual void setQuantity(int quantity);
	virtual void setUserRating(float rating);
	static list<Product> getAllProducts();
};
/* class Watch : public Product, public functions
{
	string brand;
	string model;

public:
	static string tableName;

public:
	Watch();
	Watch(std::string name, std::string description, double price, int quantity, float userRating, std::string brand, std::string model);
	string getBrand();
	string getModel();
	void setBrand(string brand);
	void setModel(string model);
}; */
class ProductInCart : public functions
{
public:
	static string tableName;
};
class Cart : public functions
{
	int id;
	vector<Product *> products;
	int userId;

public:
	static string tableName;

public:
	vector<Product *> &getProducts();
	double TotalPrice();
	void add_toCart(Product *item);
	void remove_fromCart(Product *item);
};
class User : public functions
{
	int id;
	string name;
	string pass;
	string email;
	string userAddress;
	string creditCardNumber;
	int cartId;

public:
	static string tableName;

public:
	User();
	User(string Name, string Pass, string Email);
	virtual void Greeting() = 0;
	void setName(string Name);
	void setPass(string Pass);
	void setEmail(string Email);
	void setAddress(string Address);
	virtual void setId(int id);
	virtual void setCartId(int cartId);
	int getId();
	string getName();
	string getPass();
	string getEmail();
	string getAddress();
	string getCreditCardNumber();
	// virtual Cart *getCart() = 0;
};

class RegisteredUser : public User
{
public:
	void setId(int id) override;
	void setCartId(int cartId) override;
	RegisteredUser();
	void Greeting() override;
	RegisteredUser(string name, string password, std::string email);
	Cart *getCart();

private:
	Cart cart;
};

class UnRegisteredUser : public User
{
public:
	UnRegisteredUser();
	void Greeting() override;
	RegisteredUser Login();
	bool signUp();
};

class Payment : public functions
{
	int id;
	int userId;
	double value;

public:
	static string tableName;

public:
	void process_payment(string credit_card_number);
	int getUserId();
	int getValue();
};
#endif
