#pragma once
#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include<string>
#include<vector>

using namespace std;

class Product {
	int id;
	string name;
	string descreiption;
	double price;
	int quantity;
	float userRating;
public:
	Product();
	Product(string nameproduct, string Descreiption, double Price, int Quantity, float UserRating);
	void setPrice(double Price);
	void setName(string nameproduct);
	void setDescreiption(string Descreiption);
	void setQuantity(int quant);
	void setUserRating(float rate);
	double getPrice();
	string getNameofproduct();
	string getDescription();
	int getQuantity();
	float getUserRating();
};

class Cart {
	int id;
	vector<Product*> products;
	int userId;

public:
	// What are the following 2 functions intended to do ?
	void removeCart(Product* item);
	void addCart(Product* item);

	double TotalPrice();
	void add_toCart(Product* item);
	void remove_fromCart(Product* item);
};

class User {
	int id;
	string name;
	string pass;
	string email;
	string userAddress;
	//std::string creditCardNumber;
	// Cart usercart; * Use CartId Instead
	int cartId;

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
	// The following two functions will be at class Cart
	// void add_toCart(Product* item);
	// void remove_fromCart(Product* item);
	double show_totalPrice();
};

class payment {
	// User user;
	int id;
	int userId;
public:
	void process_payment(User* user, string credit_card_number);
	void apply_discount(User* user, string discount_code);

	User user(); // get the user from db

	//discount_code زى asem100 /العص17 
};
#endif
