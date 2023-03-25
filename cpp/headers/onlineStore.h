#pragma once
#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include<string>
#include<vector>

class Product {
	std::string nameofproduct;
	std::string descreiption;
	double price;
	int quantity;
	float userRating;
public:
	Product();
	Product(std::string nameproduct, std::string Descreiption, double Price, int Quantity, float UserRating);
	void setPrice(double Price);
	void setNameofproduct(std::string nameproduct);
	void setDescreiption(std::string Descreiption);
	void setQuantity(int quant);
	void setUserRating(float rate);
	double getPrice();
	std::string getNameofproduct();
	std::string getDescreiption();
	int getQuantity();
	float getUserRating();
};

class Cart {
	std::vector<Product*> products;
public:
	void removeCart(Product* item);
	void addCart(Product* item);
	double TotalPrice();
};

class User {
	std::string name;
	std::string pass;
	std::string email;
	std::string userAddress;
	//std::string creditCardNumber;
	Cart usercart;
public:
	User();
	User(std::string Name, std::string Pass, std::string Email);
	void setName(std::string Name);
	void setPass(std::string Pass);
	void setEmail(std::string Email);
	void setAddress(std::string Address);
	std::string getName();
	std::string getPass();
	std::string getEmail();
	std::string getAddress();
	void add_toCart(Product* item);
	void remove_fromCart(Product* item);
	double show_totalPrice();
};

class payment {
	User user;
public:
	void process_payment(User* user, std::string credit_card_number);
	void apply_discount(User* user, std::string discount_code);
	//discount_code زى asem100 /العص17 

};
#endif
