#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
#include "UserPersonalInfo.h"

#include "cart.h"

using namespace std;

//class User:DB {
class User : public BaseEntity , public UserPersonalInfo {
private:
    
    int cartId;
    static string filename;
    string password;

public:
		// Getter functions
       
       
        void setPassword(const string& newPassword);

        void setCartId(int newCartId);

        void login(User* res);
        bool signUp();
        Cart getUserCart();
        string getPassword() const;
        int getCartId() const;

        vector<ProductInCart> getProductsInCart();

        string pay(float total);

        bool removeFromCart(int productId);

        // Functions for storing and reading users from file
        static void writeData(const vector<User>& users);
        static vector<User> readData();

};