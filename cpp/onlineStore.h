#pragma once
#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include <string>
#include <vector>

using namespace std;

class Product
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
	Product(string nameproduct, string Descreiption, double Price, int Quantity, float UserRating);
	virtual ~Product();
	virtual double getPrice();
	virtual string getName();
	virtual string getDescription();
	virtual int getQuantity();
	virtual float getUserRating();
	virtual void setPrice(double price);
	virtual void setName(string name);
	virtual void setDescription(string description);
	virtual void setQuantity(int quantity);
	virtual void setUserRating(float rating);
};
class Watch : public Product
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
};
class ProductInCart
{
public:
	static string tableName;
};
class Cart
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
class User
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
	void setName(string Name);
	void setPass(string Pass);
	void setEmail(string Email);
	void setAddress(string Address);
	string getName();
	string getPass();
	string getEmail();
	string getAddress();
	double show_totalPrice();
	virtual Cart *getCart() = 0;
};
class RegisteredUser : public User
{
public:
	RegisteredUser();
	RegisteredUser(string name, string password, std::string email);
	Cart *getCart() override;

private:
	Cart cart;
};
class Payment
{
	int id;
	int userId;

public:
	static string tableName;

public:
	void process_payment(string credit_card_number);
	void apply_discount(string discount_code);
};
#endif
