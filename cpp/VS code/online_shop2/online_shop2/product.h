#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

//#include "db.h"

using namespace std;

//class Product: DB {
class Product {
private:
    int id;
    string name;
    string description;
    double price;
    int quantity;
    float userRating;
    static string filename;

public:
    Product();
    Product(int id, string nameproduct, string Descreiption, double Price, int Quantity, float UserRating);
    // Getter functions
    int getId() const;
    string getName() const ;
    string getDescription() const ;
    double getPrice() const ;
    int getQuantity() const ;
    float getUserRating() const ;

    // Setter functions
    void setId(int newId) ;
    void setName(const string& newName) ;
    void setDescription(const string& newDescription) ;
    void setPrice(double newPrice) ;
    void setQuantity(int newQuantity) ;
    void setUserRating(float newUserRating) ;

    // Functions for storing and reading products from file
    static void writeData(const vector<Product>& products) ;
    static vector<Product> readData();
    
};