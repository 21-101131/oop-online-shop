#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "productInCart.h"

// #include "db.h"

using namespace std;

// class Cart: DB {
class Cart
{
private:
    int id;
    int userId;
    vector<int> productIds;
    static const string filename;

public:
    Cart();
    Cart(int id);
    // Getter functions
    int getId() const;

    int getUserId() const;
    // Setter functions
    void setId(int newId);

    bool add_toCart(Product selectedProduct, int quantity);

    // Functions for storing and reading carts from file
    static void writeData(const vector<Cart> &carts);
    static vector<Cart> readData();
};
