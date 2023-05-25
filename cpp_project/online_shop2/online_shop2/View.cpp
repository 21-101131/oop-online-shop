#include "View.h"
//#include "Selection.h"

#include<iostream>

using namespace std;

void View::displayProductsInCart(vector<ProductInCart> productsInCart){
    cout << "Products In Cart: " << endl;
    int counter = 1;
    double total = 0;
    for (ProductInCart productInCart : productsInCart) {
        Product product = productInCart.getProduct();
        double productTotal = productInCart.getCount() * product.getPrice();
        cout << counter << ") " << productInCart.getCount() << " of " << product.getName() << "\t\t" << productInCart.getCount() << " * " << product.getPrice() << " = " << productTotal << "$" << endl;
        total += productTotal;
        counter++;
    }
    cout << "TOTAL:\t" << total << endl;
}
