<<<<<<< HEAD
#pragma once
#ifndef DB_FUNCTIONS_H
#define DB_FUNCTIONS_H
#endif
=======
#ifndef DB_FUNCTIONS_H
#define DB_FUNCTIONS_H

// #include <stdlib.h>
#include <iostream>
#include <windows.h>
// #include <sqltypes.h>
// #include <sqlext.h>
// #include <sql.h>
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include <string>
// #include <list>
#include <vector>
// #include <cctype>

using namespace std;
using namespace sql;

// for demonstration only. never save your password in the code!
const string server = "sql8.freemysqlhosting.net";
const string username = "sql8613256";
const string password = "hwIw3Fjflu";

class functions
{
    static Connection* con;

public:
    static void connectsql();
    static void closeConnection();
    static vector<Product> getProductList();

protected:
    static ResultSet* select(string tableName, string condition);
    static ResultSet* getLastCreatedId(string tableName);
    static vector<Product> getProductsInCart(int cartId);
    static bool isProductInCart(int cartId, int productId);
    static bool addProductInCart(int cartId, int productId, int count);
    static bool removeFromCart(int cartId, int productId);
    static bool createUser(UnRegisteredUser user);
    static string savePayment(Payment payment);
    static RegisteredUser authenticateUser(UnRegisteredUser user);
};

#endif // DB_FUNCTIONS_H
>>>>>>> a4e04a58654800e474ed77f353082d97cdd7879f
