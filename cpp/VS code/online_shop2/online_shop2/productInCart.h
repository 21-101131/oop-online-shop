#include <vector>
#include <string>

//#include "db.h"

//class ProductInCart: DB{
class ProductInCart{
private:
    int id;
    int cartId;
    int productId;
    int count;
    static const std::string filename;

public:
    // Getter functions
    int getId() const;

    int getCartId() const;

    int getProductId() const;

    int getCount() const;

    // Setter functions
    void setId(int newId);

    void setCartId(int newCartId);

    void setProductId(int newProductId);

    void setCount(int newCount);

    // Functions for storing and reading product items in a cart from file
    //static void writeData(const std::vector<ProductInCart>& items);
    //static vector<ProductInCart> readData();

    static void writeData(const vector<ProductInCart>& items);
    static vector<ProductInCart> readData();
};