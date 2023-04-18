#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "payment.h"

// Getter functions
int Payment::getId() const {
	return id;
}

int Payment::getUserId() const {
	return userId;
}

double Payment::getValue() const {
	return value;
}

// Setter functions
void Payment::setId(int newId) {
	id = newId;
}

void Payment::setUserId(int newUserId) {
	userId = newUserId;
}

void Payment::setValue(double newValue) {
	value = newValue;
}

// Functions for storing and reading payments from file
void Payment::writeData(const vector<Payment>& payments) {
	ofstream file(filename);

	if (file.is_open()) {
		// Write header row
		file << "ID\tUser ID\tValue\n";

		// Write each payment to file
		for (const auto& payment : payments) {
			file << payment.getId() << '\t'
				<< payment.getUserId() << '\t'
				<< payment.getValue() << '\n';
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for writing.");
	}
}

vector<Payment> Payment::readData() {
	vector<Payment> payments;

	ifstream file(filename);

	if (file.is_open()) {
		string line;
		getline(file, line); // Skip header row.

		while (getline(file, line)) {
			Payment payment;

			istringstream iss(line);
			if (!(iss >> payment.id >> payment.userId >> payment.value)) {
				throw runtime_error("Invalid file format.");
			}

			payments.push_back(payment);
		}

		file.close();
	}
	else {
		throw runtime_error("Unable to open file for reading.");
	}

	return payments;
}

const string Payment::filename = "payments.txt";