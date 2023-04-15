package com.oop.online_shop;

public class Main {

	public static void main(String[] args) {
		
		System.out.println("*********************************************************************");
		System.out.println("\t\t\tWelcome to TickTock Watches");
		System.out.println("*********************************************************************");
		
		System.out.println("");
		System.out.println("Click on the number of the product to add to cart");
		System.out.println("");
		Product p1 = new Product("Rolex Daytona");
		Product p2= new Product("Casio");
		Product p3 = new Product("Tissot");
		Product p4 = new Product("AP");
		System.out.println("1)" + p1.getName());
		System.out.println("2)" + p2.getName());
		System.out.println("3)" + p3.getName());
		System.out.println("4)" + p4.getName());
		
	}

}
