#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

// #include "db.h"

using namespace std;

// class Payment:DB {
class Payment
{
private:
    int id;
    int userId;
    double value;
    static const string filename;

public:
    Payment(int id, int userId, double value);
    // Getter functions
    int getId() const;
    int getUserId() const;
    double getValue() const;

    // Setter functions
    void setId(int newId);
    void setUserId(int newUserId);
    void setValue(double newValue);

    // Functions for storing and reading payments from file
    static void writeData(const vector<Payment> &payments);
    static vector<Payment> readData();
    static string savePayment(Payment payment, int cartId);
};
