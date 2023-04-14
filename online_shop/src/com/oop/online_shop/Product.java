package com.oop.online_shop;

public class Product {
    private int id;
    private String name;
    private String description;
    private double price;
    private int quantity;
    private float userRating;
    public Product(int id, String name, String descreiption, double price, int quantity, float userRating){
        this.id = id;
        this.name = name;
        this.description = descreiption;
        this.price = price;
        this.quantity = quantity;
        this.userRating = userRating;
    }
}
