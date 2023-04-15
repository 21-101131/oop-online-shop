package com.oop.online_shop;

public class User extends DBConnection{
    public static String tableName = "User";
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
    
    public User(String name, String pass, String email, String address, String creditCardNumber) {
        this.name = name;
        this.pass = pass;
        this.email = email;
        this.userAddress = address;
        this.creditCardNumber = creditCardNumber;
    }
    public void setId(int id){this.id = id;}
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
        return this.name;
    }
    
    public String getPass() {
        return this.pass;
    }
    
    public String getEmail() {
        return this.email;
    }
    
    public String getAddress() {
        return this.userAddress;
    }

    public String getCreditCardNumber() {
        return this.creditCardNumber;
    }

    public boolean signUp(){
        return DBConnection.createUser(this);
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

