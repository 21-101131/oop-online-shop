#include<iostream>
#include<string>
#include<vector>
#include"onlineStore.h"
Product::Product() {
}
Product::Product(string nameproduct, string Descreiption, double Price, int Quantity, float UserRating) {
    this->name = nameproduct;
    this->descreiption = Descreiption;
    this->price = Price;
    this->quantity = Quantity;
    this->userRating = UserRating;
}
void Product::setPrice(double Price) {
    this->price = Price;
}
void Product::setName(string nameproduct) {
    this->name = nameproduct;
}
void Product::setDescription(string Descreiption) {
    this->descreiption = Descreiption;
}
void Product::setQuantity(int quant) {
    this->quantity = quant;
}
void Product::setUserRating(float rate) {
    this->userRating = rate;
}
double Product::getPrice() {
    return this->price;
}
string Product::getName() {
    return this->name;
}
string Product::getDescription() {
    return this->descreiption;
}
int Product::getQuantity() {
    return this->quantity;
}
float Product::getUserRating() {
    return this->userRating;
}
Watch::Watch() : Product(), brand(""), model("") {}
Watch::Watch(string name, string description, double price, int quantity, float userRating, std::string brand, std::string model)
    : Product(name, description, price, quantity, userRating), brand(brand), model(model) {}
string Watch::getBrand() {
    return brand;
}
string Watch::getModel() {
    return model;
}

void Watch::setBrand(string brand) {
    this->brand = brand;
}

void Watch::setModel(string model) {
    this->model = model;
}
double Cart::TotalPrice() {
    double total = 0;
    for (auto product : products) {
        total += product->getPrice();
    }
    return total;
}
void Cart::add_toCart(Product* item) {
    this->products.push_back(item);
}
void Cart::remove_fromCart(Product* item) {
    this->products.erase(remove(this->products.begin(), this->products.end(), item), this->products.end());
}
User::User() : id(0), cartId(0) {}

User::User(string name, string pass, string email) :
    id(0), name(name), pass(pass), email(email), cartId(0) {}

void User::setName(string name) {
    this->name = name;
}

void User::setPass(string pass) {
    this->pass = pass;
}

void User::setEmail(string email) {
    this->email = email;
}

void User::setAddress(string address) {
    this->userAddress = address;
}

string User::getName() {
    return name;
}

string User::getPass() {
    return pass;
}

string User::getEmail() {
    return email;
}

string User::getAddress() {
    return userAddress;
}

double User::show_totalPrice() {
    Cart* userCart = getCart();
    if (userCart) {
        return userCart->TotalPrice();
    }
    return 0.0;
}

RegisteredUser::RegisteredUser() {}

RegisteredUser::RegisteredUser(string name, string password, std::string email) :
    User(name, password, email) {}

Cart* RegisteredUser::getCart() {
    return &cart;
}


void payment::process_payment(string credit_card_number) {
    // process the payment using the provided credit card number from dp
   //dp
}

void payment::apply_discount( string discount_code) {
  
}


