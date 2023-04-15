package com.oop.online_shop;

import java.util.ArrayList;

public class Cart {
    private int id;
    private ArrayList<Product> products;
    private int userId;
    
    public double TotalPrice() {
        double totalPrice = 0.0;
        for (Product product : products) {
            totalPrice += product.getPrice();
        }
        return totalPrice;
    }
    
    public void add_toCart(Product item) {
        products.add(item);
    }
    
    public void removeCart(Product item) {
        products.remove(item);
    }
    
    public void remove_fromCart(Product item) {
        products.remove(item);
    }
    
    public void remove_fromCart(int index) {
        products.remove(index);
    }
}
