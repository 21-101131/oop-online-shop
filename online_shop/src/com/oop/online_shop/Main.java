package com.oop.online_shop;
import com.oop.online_shop.DBConnection;
public class Main {
    public static void main(String[] args) {
        DBConnection myConn = new DBConnection();
        myConn.connect();
        System.out.println("Heyyyy, what do you know it's working!");
        myConn.closeConnection();
    }
}
