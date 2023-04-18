#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

//#include "db.h"

using namespace std;

//class User:DB {
class User {
private:
    int id;
    string name;
    string password;
    string email;
    string userAddress;
    string creditCardNumber;
    int cartId;
    static string filename;

public:
		// Getter functions
		int getId() const;
        string getName() const;
        string getPassword() const;
        string getEmail() const;
        string getUserAddress() const;
        string getCreditCardNumber() const;
        int getCartId() const;

        // Setter functions
        void setId(int newId);

        void setName(const string& newName);

        void setPassword(const string& newPassword);

        void setEmail(const string& newEmail);

        void setUserAddress(const string& newUserAddress);

        void setCreditCardNumber(const string& newCreditCardNumber);

        void setCartId(int newCartId);

        // Functions for storing and reading users from file
        static void writeData(const vector<User>& users);
        static vector<User> readData();

};