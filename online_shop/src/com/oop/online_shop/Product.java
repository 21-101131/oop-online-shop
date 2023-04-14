package com.oop.online_shop;

public class Product extends DBConnection {
    private int id;
    private String name;
    private String description;
    private double price;
    private int quantity;
    private float userRating;
    static String tableName = "Products";
    public Product(int id, String name, String description, double price, int quantity, float userRating){
        this.id = id;
        this.name = name;
        this.description = description;
        this.price = price;
        this.quantity = quantity;
        this.userRating = userRating;
    }
}
