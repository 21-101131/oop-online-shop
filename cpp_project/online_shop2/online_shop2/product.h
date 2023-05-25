#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
// #include "db.h"

#include "payment.h"
#include "ProductInfo.h"

using namespace std;

// class Product: DB {
class Product: public BaseEntity , public ProductInfo
{
private:
   
    int quantity;
    float userRating;
    static string filename;

public:
    Product();
    Product(int id, string nameproduct, string Descreiption, double Price, int Quantity, float UserRating);
    // Getter functions
   
    int getQuantity() const;
    float getUserRating() const;

    // Setter functions
   
    void setQuantity(int newQuantity);
    void setUserRating(float newUserRating);
    bool decreaseProductQuantity(int num);
    // Functions for storing and reading products from file
    static void writeData(const vector<Product> &products);
    static vector<Product> readData();
};