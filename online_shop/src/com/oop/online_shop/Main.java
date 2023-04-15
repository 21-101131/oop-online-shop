package com.oop.online_shop;

public class Main {

	public static void main(String[] args) {
		// connect the database
		DBConnection.connect();
		
		System.out.println("*********************************************************************");
		System.out.println("\t\t\tWelcome to TickTock Watches");
		System.out.println("*********************************************************************");
		
		System.out.println("");
		System.out.println("Click on the number of the product to add to cart");
		System.out.println("");
		for(Product product : Product.getAllProducts()){
			System.out.println(product.getId() + ") " + product.getName());
		}

		//Product p1 = new Product("Rolex Daytona");
		//Product p2= new Product("Casio");
		//Product p3 = new Product("Tissot");
		//Product p4 = new Product("AP");

		//System.out.println("1)" + p1.getName());
		//System.out.println("2)" + p2.getName());
		//System.out.println("3)" + p3.getName());
		//System.out.println("4)" + p4.getName());
		//User testUser = new User(
		//		"Abdullah",
		//		"Aa123456",
		//		"test@test.test",
		//		"my address",
		//		"0123456789012345"
		//);

		//System.out.println(testUser.signUp());
		//System.out.println("end");

		// Disconnect database
		DBConnection.closeConnection();
	}

}
