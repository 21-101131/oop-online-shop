package com.oop.online_shop;
import java.sql.*;

public class DBConnection {
    private Connection con;

    public void connect() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection(
                    "jdbc:mysql://sql8.freemysqlhosting.net:3306/sql8612103",
                    "sql8612103",
                    "m624G5CJxr"
            );

            System.out.println("Connection Started");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }



    //Statement stmt=con.createStatement();
   // ResultSet rs=stmt.executeQuery("select * from emp");
	//		while(rs.next())
   //                 System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));

    public void closeConnection() {
        try {
            con.close();
            System.out.println("Connection Closed");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
