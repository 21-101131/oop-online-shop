#include "productInCart.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

const std::string ProductInCart::filename = "productincart.csv";

// Getter functions
int ProductInCart::getId() const {
    return id;
}

int ProductInCart::getCartId() const {
    return cartId;
}

int ProductInCart::getProductId() const {
    return productId;
}

int ProductInCart::getCount() const {
    return count;
}

Product ProductInCart::getProduct() const {
    return product;
}

// Setter functions
void ProductInCart::setId(int newId) {
    id = newId;
}

void ProductInCart::setCartId(int newCartId) {
    cartId = newCartId;
}

void ProductInCart::setProductId(int newProductId) {
    productId = newProductId;
}

void ProductInCart::setCount(int newCount) {
    count = newCount;
}

// Functions for storing and reading product items in a cart from file
void ProductInCart::writeData(const std::vector<ProductInCart>& items) {
    std::ofstream file(filename);

    if (file.is_open()) {
        // Write header row
        file << "ID\tCart ID\tProduct ID\tCount\n";

        // Write each product item in cart to file
        for (const auto& item : items) {
            file << item.getId() << '\t'
                << item.getCartId() << '\t'
                << item.getProductId() << '\t'
                << item.getCount() << '\n';
        }

        file.close();
    }
    else {
        throw std::runtime_error("Unable to open file for writing.");
    }
}

std::vector<ProductInCart> ProductInCart::readData() {
    std::vector<ProductInCart> items;

    std::ifstream file(ProductInCart::filename);

    if (file.is_open()) {
        std::string line;
        getline(file, line); // Skip header row.

        while (getline(file, line)) {
            ProductInCart item;
            std::istringstream iss(line);
            if (!(iss >> item.id >> item.cartId >> item.productId >> item.count)) {
                throw std::runtime_error("Invalid file format.");
            }

            items.push_back(item);
        }

        file.close();
    }
    else {
        throw std::runtime_error("Unable to open file for reading.");
    }

    return items;
}