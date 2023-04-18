#include "cart.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

Cart::Cart() {}

Cart::Cart(int _id) : id(_id) {}

// Getter functions
int Cart::getId() const
{
	return id;
}
int Cart::getUserId() const
{
	return userId;
}

// Setter functions
void Cart::setId(int newId)
{
	id = newId;
}

bool Cart::add_toCart(Product selectedProduct, int quantity)
{
	return true;
}

// Functions for storing and reading carts from file
void Cart::writeData(const vector<Cart> &carts)
{
	/*
	ofstream file(filename);

	if (file.is_open())
	{
		// Write header row
		file << "ID\n";

		// Write each cart to file
		for (const auto &cart : carts)
		{
			file << cart.getId() << '\n';
		}

		file.close();
	}
	else
	{
		throw runtime_error("Unable to open file for writing.");
	}
	*/
	ofstream file(filename);

	if (file.is_open())
	{
		file << "id\n"; // write header row

		for (auto &cart : carts)
		{
			file << cart.id << "\n";
		}

		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}

vector<Cart> Cart::readData()
{
	vector<Cart> carts;

	ifstream file(filename);

	if (file.is_open())
	{
		string line;
		getline(file, line); // Skip header row.

		while (getline(file, line))
		{
			Cart cart;

			istringstream iss(line);
			if (!(iss >> cart.id))
			{
				throw runtime_error("Invalid file format.");
			}

			string productIdsString;
			if (getline(iss, productIdsString))
			{
				// Parse the product IDs from the comma-separated string
				stringstream ss(productIdsString);
				string productIdString;
				while (getline(ss, productIdString, ','))
				{
					cart.productIds.push_back(stoi(productIdString));
				}
			}

			carts.push_back(cart);
		}

		file.close();
	}
	else
	{
		throw runtime_error("Unable to open file for reading.");
	}

	return carts;
	* /
		vector<Cart> carts;
	ifstream file(filename);
	string line;

	if (file.is_open())
	{
		getline(file, line); // skip header row

		while (getline(file, line))
		{
			stringstream ss(line);
			string field;
			vector<string> fields;

			while (getline(ss, field, ','))
			{
				fields.push_back(field);
			}

			int id = stoi(fields[0]);

			carts.push_back(Cart(id));
		}

		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	return carts;
}

const string Cart::filename = "carts.csv";
