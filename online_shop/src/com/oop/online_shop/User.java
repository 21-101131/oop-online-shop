package com.oop.online_shop;

public class User {
    private int id;
    private String name;
    private String pass;
    private String email;
    private String userAddress;
    private String creditCardNumber;
    private int cartId;
    
    public User() {
        // Default constructor
    }
    
    public User(String name, String pass, String email) {
        this.name = name;
        this.pass = pass;
        this.email = email;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public void setPass(String pass) {
        this.pass = pass;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
    
    public void setAddress(String address) {
        this.userAddress = address;
    }
    
    public String getName() {
        return name;
    }
    
    public String getPass() {
        return pass;
    }
    
    public String getEmail() {
        return email;
    }
    
    public String getAddress() {
        return userAddress;
    }
    
    public double show_totalPrice() {
        Cart userCart = getCart();
        if (userCart != null) {
            return userCart.TotalPrice();
        }
        return 0.0;
    }

	private Cart getCart() {
		// TODO Auto-generated method stub
		return null;
	}

}

