package com.oop.online_shop;
import java.util.Scanner;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		// connect the database
		DBConnection.connect();
		//Instances 
		Scanner scanner = new Scanner(System.in);
		User u1 = new User();
		DBConnection d1 = new DBConnection();
		
		System.out.println("*********************************************************************");
		System.out.println("\t\t\tWelcome to TickTock Watches");
		System.out.println("*********************************************************************");
		
		System.out.println("");
		System.out.println("Click on the number of the product to show description");
		System.out.println("");
		List<Product> productList = Product.getAllProducts(); 
		//For loop to display all products from database
		for(Product product : productList){
			System.out.println(product.getId() + ") " + product.getName());
		}
		
		//choosing a number to show the product description
		scanner = new Scanner(System.in);
	    System.out.print("Chose a number: ");
	    int number = scanner.nextInt();
	    //for loop to show the products description
	    for(Product product : productList) {
	    	if(number == product.getId())
	    	{
	    		System.out.println("Description: " +product.getDescription());
	    		System.out.println("Price: " + product.getPrice());
	    		System.out.println("Quantity: " + product.getQuantity());
	    		System.out.println("User Rating: " + product.getUserRating());
	    		break;
	    	}
	    }
	    System.out.println("Press to 1 to add to cart");
	    System.out.println("Press to 2 to continue shopping");
	    scanner = new Scanner(System.in);
	    int number2 = scanner.nextInt();
	    
	    //if condition to direct the customer to the login page if he wants to add to the cart
	    if(number2 == 1)
    	{
    		System.out.println("Press 1 to Login");
    		System.out.println("Press 2 to Signup");
    		scanner = new Scanner(System.in);
    	    int number3 = scanner.nextInt();
    	    //Redirecting to login 
    	    if(number3 == 1)
    	    {
    	    	System.out.println("Enter Email");
    	    	scanner = new Scanner(System.in);
    	    	String email = scanner.nextLine();
    	    	System.out.println("Enter Password");
    	    	scanner = new Scanner(System.in);
    	    	String pass = scanner.nextLine();
    	    	u1.setEmail(email);
    	    	u1.setPass(pass);
    	    	u1.Login();		
    	    }
    	    //Redirecting to sign up
    	    else if(number3 == 2)
    	    {
    	    	System.out.println("Write your full name");
    	    	scanner = new Scanner(System.in);
    	    	String name = scanner.nextLine();
    	    	u1.setName(name);
    	    	
    	    	System.out.println("Write your Email");
    	    	scanner = new Scanner(System.in);
    	    	String email = scanner.nextLine();
    	    	u1.setEmail(email);
    	    	
    	    	System.out.println("Create password");
    	    	scanner = new Scanner(System.in);
    	    	String pass = scanner.nextLine();
    	    	u1.setPass(pass);
    	    	u1.signUp();
    	    }
    	}
	    //Redirects you if you want to continue shopping 
    	else if(number2 == 2)
    	{
    		for(Product product : productList){
				System.out.println(product.getId() + ") " + product.getName());
				
			}
    		scanner = new Scanner(System.in);
    	    System.out.print("Chose a number: ");
    	    int n = scanner.nextInt();
    	    //for loop to show the products description
    	    for(Product product : productList) {
    	    	if(number == product.getId())
    	    	{
    	    		System.out.println("Description: " +product.getDescription());
    	    		System.out.println("Price: " + product.getPrice());
    	    		System.out.println("Quantity: " + product.getQuantity());
    	    		System.out.println("User Rating: " + product.getUserRating());
    	    		break;
    	    	}
    	    }
    	
    	}
	    //else statement to redirect you to products if you pressed on a wrong number 
    	else {
    		System.out.println("Invalid Number");
    		System.out.println("Press to 1 to add to cart");
    	    System.out.println("Press to 2 to continue shopping");
    	    scanner = new Scanner(System.in);
    	    number2 = scanner.nextInt();
    	    if(number2 == 1)
        	{
        		System.out.println("Press 1 to Login");
        		System.out.println("Press 2 to Signup");
        	}
        	else if(number2 == 2)
        	{
        		for(Product product : productList){
    				System.out.println(product.getId() + ") " + product.getName());
    				break;
    			}
        	
        	}
    	}
	    
	     
	    
	    // Disconnect database
	 	DBConnection.closeConnection();
	
	}

}
