package com.oop.online_shop;

import java.sql.*;
import java.util.List;
import java.util.ArrayList;

public class DBConnection {
    private static Connection con = null;

    private static void connect() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            DBConnection.con = DriverManager.getConnection(
                    "jdbc:mysql://sql8.freemysqlhosting.net:3306/sql8612103",
                    "sql8612103",
                    "m624G5CJxr"
            );

        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("AHHHHHH");
        }
    }

    protected static List<Product> getProductList(){
        if(DBConnection.con == null) DBConnection.connect();

        List<Product> productList = new ArrayList<>();
        try{
            Statement stmt = DBConnection.con.createStatement();
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

    protected static boolean authenticateUser(User user){
        if(DBConnection.con == null) DBConnection.connect();

        try{
            Statement stmt = DBConnection.con.createStatement();
            ResultSet rs = stmt.executeQuery(
                    "select * from " + User.tableName
                            + " WHERE email="+ user.getEmail().toLowerCase() + " AND pass="+user.getPass());

            return rs.next();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        return false;
    }

    protected static boolean createUser(User user){
        if(DBConnection.con == null) DBConnection.connect();

        try {
            // Create Cart
            String insertSql = "INSERT INTO " + Cart.tableName + " ()" +
                    " VALUES ()";

            PreparedStatement pstmt = DBConnection.con.prepareStatement(insertSql, Statement.RETURN_GENERATED_KEYS);

            int cartId = 0;

            if(pstmt.executeUpdate() > 0){
                ResultSet rs = pstmt.getGeneratedKeys();
                if (rs.next()) {
                    cartId = rs.getInt(1);
                }
            }

            if(cartId == 0) return false;

            // Create User
            insertSql = "INSERT INTO " + User.tableName + " (name, pass, email, userAdress, creditCardNumber, cartId)" +
                    " VALUES (?, ?, ?, ?, ?, ?)";

            pstmt = DBConnection.con.prepareStatement(insertSql, Statement.RETURN_GENERATED_KEYS);

            pstmt.setString(1, user.getName());
            pstmt.setString(2, user.getPass());
            pstmt.setString(3, user.getEmail());
            pstmt.setString(4, user.getAddress());
            pstmt.setString(5, user.getCreditCardNumber());
            pstmt.setInt(6, cartId);

            int numRowsAffected = pstmt.executeUpdate();
            if(numRowsAffected > 0){
                ResultSet rs = pstmt.getGeneratedKeys();
                if (rs.next()) {
                    user.setId(rs.getInt(1));
                }
                return true;
            }

        }
        catch (Exception e){
                e.printStackTrace();
        }
        return false;
    }

    public static void closeConnection() {
        try {
            DBConnection.con.close();
            System.out.println("Connection Closed");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
