#pragma once
#include <iostream>
#include <list>
#include "onlineStore.h"
using namespace std;
int main()
{
    UnRegisteredUser u1;
    cout << "*********************************************************************" << endl
         << "\t\t\tWelcome to TickTock Watches" << endl
         << "*********************************************************************" << endl
         << "\"\"" << endl
         << "Click on the number of the product to show description" << endl
         << "\"\"" << endl;
    list<Product> productList = Product::getAllProducts();
    // For loop to display all products from database
    for (Product product : productList)
    {
        cout << product.getId() << ") " << product.getName();
    }
    int number;
    cout << "Choose a number: ";
    cin >> number;
    for (Product product : productList)
    {
        if (number == product.getId())
        {
            cout << "Description: " << product.getDescription();
            cout << "Price: " << product.getPrice();
            cout << "Quantity: " << product.getQuantity();
            cout << "User Rating: " << product.getUserRating();
            break;
        }
    }
    cout << "Press to 1 to add to cart" << endl;
    cout << "Press to 2 to continue shopping" << endl;

    // Taking input from user to add to cart or continue shopping
    int number2;
    cin >> number2;

    // if condition to direct the customer to the login page if he wants to add to the cart
    if (number2 == 1)
    {
        cout << "Press 1 to Login" << endl;
        cout << "Press 2 to Signup" << endl;

        // Taking input from user to choose between login or sign up
        int number3;
        cin >> number3;

        // Redirecting to login
        if (number3 == 1)
        {
            cout << "Enter Email" << endl;
            string email;
            cin >> email;

            cout << "Enter Password" << endl;
            string pass;
            cin >> pass;

            u1.setEmail(email);
            u1.setPass(pass);
            u1.Login();
        }
        // Redirecting to sign up
        else if (number3 == 2)
        {
            cout << "Write your full name" << endl;
            string name;
            cin >> name;
            u1.setName(name);

            cout << "Write your Email" << endl;
            string email;
            cin >> email;
            u1.setEmail(email);

            cout << "Create password" << endl;
            string pass;
            cin >> pass;
            u1.setPass(pass);
            u1.signUp();
        }
    }
}