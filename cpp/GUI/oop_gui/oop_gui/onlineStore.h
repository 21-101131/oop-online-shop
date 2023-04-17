#pragma once
#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include<string>
#include<vector>

using namespace std;

ref class Product {
	int id;
	String^ name;
	String^ descreiption;
	double price;
	int quantity;
	float userRating;
public:
	Product();
	Product(String^ nameproduct, String^ Descreiption, double Price, int Quantity, float UserRating);
	virtual ~Product();
	virtual double getPrice();
	virtual String^ getName() ;
	virtual String^ getDescription();
	virtual int getQuantity() ;
	virtual float getUserRating();
	virtual void setPrice(double price);
	virtual void setName(String^ name);
	virtual void setDescription(String^ description);
	virtual void setQuantity(int quantity);
	virtual void setUserRating(float rating);
};
ref class Watch : public Product {
	String^ brand;
	String^ model;
public:
	Watch();
	Watch(String^ name, String^ description, double price, int quantity, float userRating, String^ brand, String^ model);
	String^ getBrand();
	String^ getModel();
	void setBrand(String^ brand);
	void setModel(String^ model);
};
ref class Cart {
	int id;
	vector<Product^> *products;
	int userId;

public:
	vector<Product^> & getProducts();
	double TotalPrice();
	void add_toCart(Product^ item);
	void remove_fromCart(Product^ item);
};
ref class User {
	int id;
	String^ name;
	String^ pass;
	String^ email;
	String^ userAddress;
	String^ creditCardNumber;
	int cartId;

public:
	User();
	User(String^ Name, String^ Pass, String^ Email);
	void setName(String^ Name);
	void setPass(String^ Pass);
	void setEmail(String^ Email);
	void setAddress(String^ Address);
	String^ getName();
	String^ getPass();
	String^ getEmail();
	String^ getAddress();
	double show_totalPrice();
	virtual Cart^ getCart() = 0;
};
ref class RegisteredUser : public User {
public:
	RegisteredUser();
	RegisteredUser(String^ name, String^ password, String^ email);
	Cart^ getCart() override;
private:
	Cart cart;
};
ref class payment {
	int id;
	int userId;
public:
	void process_payment(String^ credit_card_number);
	void apply_discount(String^ discount_code);
};
#endif
