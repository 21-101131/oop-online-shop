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
void Product::setDescreiption(string Descreiption) {
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
string Product::getNameofproduct() {
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
User::User() {
    
}
User::User(string Name, string Pass, string Email) {
    this->name = Name;
    this->pass = Pass;
    this->email = Email;
}
void User::setName(string Name) {
    this->name = Name;
}
void User::setPass(string Pass) {
    this->pass = Pass;
}
void User::setEmail(string Email) {
    this->email = Email;
}
void User::setAddress(string Address) {
    this->userAddress = Address;
}
string User::getName() {
    return this->name;
}
string User::getPass() {
    return this->pass;
}
string User::getEmail() {
    return this->email;
}
string User::getAddress() {
    return this->userAddress;
}
double User::show_totalPrice() {
    return Cart.TotalPrice();
}
void payment::process_payment(string credit_card_number) {
    // process the payment using the provided credit card number from dp
   //dp
}

void payment::apply_discount( string discount_code) {
    //معتمدة عل dp
// متنساش تعمل اكواد خصم ف الداتا بيز
}


