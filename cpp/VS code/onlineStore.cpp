#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include "onlineStore.h"

Product::Product()
{
}
Product::Product(int id, string nameproduct, string Descreiption, double Price, int Quantity, float UserRating)
{
    this->id = id;
    this->name = nameproduct;
    this->descreiption = Descreiption;
    this->price = Price;
    this->quantity = Quantity;
    this->userRating = UserRating;
}
void Product::setPrice(double Price)
{
    this->price = Price;
}
void Product::setName(string nameproduct)
{
    this->name = nameproduct;
}
void Product::setDescription(string Descreiption)
{
    this->descreiption = Descreiption;
}
void Product::setQuantity(int quant)
{
    this->quantity = quant;
}
void Product::setUserRating(float rate)
{
    this->userRating = rate;
}
double Product::getPrice()
{
    return this->price;
}
string Product::getName()
{
    return this->name;
}
int Product::getId()
{
    return this->id;
}
string Product::getDescription()
{
    return this->descreiption;
}
int Product::getQuantity()
{
    return this->quantity;
}
float Product::getUserRating()
{
    return this->userRating;
}
vector<Product> getAllProducts()
{
    return functions::getProductList<Product>();
}
/* Watch::Watch() : Product(), brand(""), model("") {}
Watch::Watch(string name, string description, double price, int quantity, float userRating, std::string brand, std::string model)
    : Product(name, description, price, quantity, userRating), brand(brand), model(model) {}
string Watch::getBrand()
{
    return brand;
}
string Watch::getModel()
{
    return model;
}

void Watch::setBrand(string brand)
{
    this->brand = brand;
}

void Watch::setModel(string model)
{
    this->model = model;
} */
double Cart::TotalPrice()
{
    double total = 0;
    for (auto product : products)
    {
        total += product->getPrice();
    }
    return total;
}
void Cart::add_toCart(Product *item)
{
    this->products.push_back(item);
}
void Cart::remove_fromCart(Product *item)
{
    this->products.erase(remove(this->products.begin(), this->products.end(), item), this->products.end());
}
User::User() : id(0), cartId(0) {}

User::User(string name, string pass, string email) : id(0), name(name), pass(pass), email(email), cartId(0) {}

void User::setName(string name)
{
    this->name = name;
}

void User::setPass(string pass)
{
    this->pass = pass;
}

void User::setEmail(string email)
{
    this->email = email;
}

void User::setAddress(string address)
{
    this->userAddress = address;
}

void User::setId(int id)
{
    this->id = id;
}

void User::setCartId(int cartId)
{
    this->cartId = cartId;
}

string User::getName()
{
    return name;
}

string User::getPass()
{
    return pass;
}
int User::getId()
{
    return id;
}
string User::getEmail()
{
    return email;
}

string User::getAddress()
{
    return userAddress;
}

string User::getCreditCardNumber()
{
    return creditCardNumber;
}

/* double User::show_totalPrice()
{
    Cart *userCart = getCart();
    if (userCart)
    {
        return userCart->TotalPrice();
    }
    return 0.0;
} */

UnRegisteredUser::UnRegisteredUser() {}

RegisteredUser UnRegisteredUser::Login()
{
    return authenticateUser<RegisteredUser, UnRegisteredUser>(*this);
}

bool UnRegisteredUser::signUp()
{
    return createUser(*this);
}
void UnRegisteredUser::Greeting()
{
    cout << "Welcome to our store!";
}

RegisteredUser::RegisteredUser() {}

void RegisteredUser::setId(int id)
{
    User::setId(id);
}

void RegisteredUser::Greeting()
{
    cout << "Welcome " << getName() << "!";
}

void RegisteredUser::setCartId(int cartId)
{
    User::setCartId(cartId);
}

RegisteredUser::RegisteredUser(string name, string password, std::string email) : User(name, password, email) {}

Cart *RegisteredUser::getCart()
{
    return &cart;
}

void Payment::process_payment(string credit_card_number)
{
    // process the payment using the provided credit card number from dp
    // dp
}

int Payment::getUserId()
{
    return this->userId;
}

int Payment::getValue()
{
    return this->value;
}

string Product::tableName = "Products";

string ProductInCart::tableName = "ProductInCart";

string Cart::tableName = "Cart";

string User::tableName = "User";

string Payment::tableName = "Payment";
