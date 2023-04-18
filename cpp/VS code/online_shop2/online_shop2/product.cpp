#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
#include "product.h"

using namespace std;

string Product::filename = "products.txt";

Product::Product(){}
Product::Product(int id, string nameproduct, string Descreiption, double Price, int Quantity, float UserRating)
{
	this->id = id;
	this->name = nameproduct;
	this->description = Descreiption;
	this->price = Price;
	this->quantity = Quantity;
	this->userRating = UserRating;
}
// Getter functions
int Product::getId() const {
	return id;
}

string Product::getName() const {
	return name;
}

string Product::getDescription() const {
	return description;
}

double Product::getPrice() const {
	return price;
}

int Product::getQuantity() const {
	return quantity;
}

float Product::getUserRating() const {
	return userRating;
}

// Setter functions
void Product::setId(int newId) {
	id = newId;
}

void Product::setName(const string& newName) {
	name = newName;
}

void Product::setDescription(const string& newDescription) {
	description = newDescription;
}

void Product::setPrice(double newPrice) {
	price = newPrice;
}

void Product::setQuantity(int newQuantity) {
	quantity = newQuantity;
}

void Product::setUserRating(float newUserRating) {
	userRating = newUserRating;
}

// Functions for storing and reading products from file
void Product::writeData(const vector<Product>& products) {
	ofstream file(Product::filename);

	if (file.is_open()) {
		// Write header row
		file << "ID\tName\tDescription\tPrice\tQuantity\tUser Rating\n";

		// Write each product to file
		for (const auto& product : products) {
			file << product.getId() << '\t'
				<< product.getName() << '\t'
				<< product.getDescription() << '\t'
				<< product.getPrice() << '\t'
				<< product.getQuantity() << '\t'
				<< product.getUserRating() << '\n';
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for writing.");
	}
}

vector<Product> Product::readData() {
	vector<Product> products;

	ifstream file(Product::filename);
	if (file.is_open()) {
		string line;
		getline(file, line); // Skip header row.

		while (getline(file, line)) {
			Product product;

			istringstream iss(line);
			if (!(iss >> product.id >> product.name >> product.description
				>> product.price >> product.quantity >> product.userRating)) {
				throw runtime_error("Invalid file format.");
			}

			products.push_back(product);
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for reading.");
	}

	return products;
}
