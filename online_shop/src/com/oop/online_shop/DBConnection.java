package com.oop.online_shop;

import java.sql.*;
import java.util.List;
import java.util.ArrayList;

public class DBConnection {
    private Connection con;

    public void connect() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            this.con = DriverManager.getConnection(
                    "jdbc:mysql://sql8.freemysqlhosting.net:3306/sql8612103",
                    "sql8612103",
                    "m624G5CJxr"
            );

            System.out.println("Connection Started");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected List<Product> getProductList(){
        List<Product> productList = new ArrayList<>();
        try{
            Statement stmt = this.con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from " + Product.tableName);

            while(rs.next()) {
                productList.add(
                    new Product(
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("description"),
                        rs.getDouble("price"),
                        rs.getInt("quantity"),
                        rs.getFloat("userRating")
                    )
                );
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }

        return productList;
    }


    public void closeConnection() {
        try {
            this.con.close();
            System.out.println("Connection Closed");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
