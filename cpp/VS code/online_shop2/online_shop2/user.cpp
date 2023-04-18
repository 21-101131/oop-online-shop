#include <iostream>
#include "user.h"

using namespace std;

string User::filename = "users.txt";

// Getter functions
int User::getId() const {
	return id;
}

string User::getName() const {
	return name;
}

string User::getPassword() const {
	return password;
}

string User::getEmail() const {
	return email;
}

string User::getUserAddress() const {
	return userAddress;
}

string User::getCreditCardNumber() const {
	return creditCardNumber;
}

int User::getCartId() const {
	return cartId;
}

// Setter functions
void User::setId(int newId) {
	id = newId;
}

void User::setName(const string& newName) {
	name = newName;
}

void User::setPassword(const string& newPassword) {
	password = newPassword;
}

void User::setEmail(const string& newEmail) {
	email = newEmail;
}

void User::setUserAddress(const string& newUserAddress) {
	userAddress = newUserAddress;
}

void User::setCreditCardNumber(const string& newCreditCardNumber) {
	creditCardNumber = newCreditCardNumber;
}

void User::setCartId(int newCartId) {
	cartId = newCartId;
}

User* User::login() {
	User* u = new User();
	return u;
}

bool User::signUp(){
	return true;
}

Cart User::getUserCart(){
	Cart c;
	return c;
}

vector<ProductInCart> User::getProductsInCart(){
	vector<ProductInCart> v;
	return v;
}

string User::pay(float total){
	return "";
}

bool User::removeFromCart(int productId) {
	return true;
}

// Functions for storing and reading users from file
void User::writeData(const vector<User>& users) {
	/*
	ofstream file(filename);

	if (file.is_open()) {
		// Write header row
		file << "ID\tName\tPassword\tEmail\tAddress\tCredit Card Number\tCart ID\n";

		// Write each user to file
		for (const auto& user : users) {
			file << user.getId() << '\t'
				<< user.getName() << '\t'
				<< user.getPassword() << '\t'
				<< user.getEmail() << '\t'
				<< user.getUserAddress() << '\t'
				<< user.getCreditCardNumber() << '\t'
				<< user.getCartId() << '\n';
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for writing.");
	}*/
	ofstream csvFile(filename);
	if (csvFile) {
		csvFile << "id,name,pass,email,user_address,credit_card_number,cart_id" << endl;
		for (const auto& user : users) {
			csvFile << user.id << ","
				<< user.name << ","
				<< user.password << ","
				<< user.email << ","
				<< user.userAddress << ","
				<< user.creditCardNumber << ","
				<< user.cartId << endl;
		}
		csvFile.close();
	}
	else {
		cout << "Error opening file: " << filename << endl;
	}
}

vector<User> User::readData() {
	/*vector<User> users;

	ifstream file(User::filename);

	if (file.is_open()) {
		string line;
		getline(file, line); // Skip header row.

		while (getline(file, line)) {
			User user;

			istringstream iss(line);
			if (!(iss >> user.id >> user.name >> user.password
				>> user.email >> user.userAddress >> user.creditCardNumber >> user.cartId)) {
				throw runtime_error("Invalid file format.");
			}

			users.push_back(user);
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for reading.");
	}

	return users;
	*/
	vector<User> users;
	ifstream csvFile(filename);
	if (csvFile) {
		// Ignore the header line
		string header;
		getline(csvFile, header);

		string line;
		while (getline(csvFile, line)) {
			stringstream ss(line);
			string token;

			// Parse the CSV line into User attributes
			User user;
			getline(ss, token, ',');
			user.id = stoi(token);
			getline(ss, user.name, ',');
			getline(ss, user.password, ',');
			getline(ss, user.email, ',');
			getline(ss, user.userAddress, ',');
			getline(ss, user.creditCardNumber, ',');
			getline(ss, token, ',');
			user.cartId = stoi(token);

			users.push_back(user);
		}

		csvFile.close();
	}
	else {
		cout << "Error opening file: " << filename << endl;
	}

	return users;
}
