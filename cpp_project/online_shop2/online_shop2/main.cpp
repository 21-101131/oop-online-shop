#include <iostream>
#include <vector>

//#include "user.h"
#include "Controller.h"

using namespace std;

//class Main {
//	static void showCart(){
//		vector<ProductInCart> productsInCart = user->getProductsInCart();
//		if(productsInCart.size() == 0){
//			cout << "Cart is empty!" << endl;
//			return;
//		}
//		cout << "Products In Cart: " << endl;
//		int counter = 1;
//		double total = 0;
//		for (ProductInCart productInCart : productsInCart) {
//			Product product = productInCart.getProduct();
//			double productTotal = productInCart.getCount() * product.getPrice();
//			cout << counter << ") " << productInCart.getCount() << " of " << product.getName() << "\t\t" << productInCart.getCount() << " * " << product.getPrice() << " = " << productTotal << "$" << endl;
//			total += productTotal;
//			counter++;
//		}
//
//		cout << "TOTAL:\t" << total << endl;
//
//		cout << "\n1.Proceed Payment" << endl;
//		cout << "2.Remove product from cart" << endl;
//		cout << "Choose a number ( enter 0 to go back ): " << endl;
//		int number;
//		cin >> number;
//		switch (number){
//			case 1:
//				cout << user->pay((float)total) << endl << "Products will arrive you at " << user->getUserAddress();
//				for (ProductInCart productInCart : productsInCart) {
//					productInCart.getProduct().decreaseProductQuantity(productInCart.getCount());
//				}
//				break;
//
//			case 2:
//				cout << "Enter the number of product to remove from cart: " << endl;
//				cin >> number;
//				if(user->removeFromCart(productsInCart[number-1].getProduct().getId())) cout << "Product removed successfully!" << endl;
//				cout << "Here is the cart after edit:" << endl;
//				showCart();
//				break;
//		}
//	}
//public:
//	static User* user;
//
//	static void userLogin(){
//		cout << "Login Please:" << endl;
//		do {
//			user = new User();
//
//			cout << "Enter Email: " << endl;
//			string email;
//			cin >> email;
//			user->setEmail(email);
//
//			cout << "Enter Password: " << endl;
//			string pass;
//			cin >> pass;
//			user->setPassword(pass);
//
//			user->login(user);
//
//			if (!user) cout << "Wrong email or password. Try Again: " << endl;
//		} while (!user);
//		cout << "Logged in successfully!\n" << endl;
//	}
//
//	static void userSignup(){
//		user = new User();
//
//		cout << "Write your full name" << endl;
//		string name;
//		cin >> name;
//		user->setName(name);
//				
//		cout << "Write your Email" << endl;
//		string email;
//		cin >> email;
//		user->setEmail(email);
//
//		cout << "Enter password" << endl;
//		string password;
//		cin >> password;
//		user->setPassword(password);
//
//		cout << "Enter address" << endl;
//		string address;
//		cin >> address;
//		user->setUserAddress(address);
//
//		cout << "Enter credit card number" << endl;
//		string creditCardNumber;
//		cin >> creditCardNumber;
//		user->setCreditCardNumber(creditCardNumber);
//
//		if(user->signUp()) {
//			cout << "Signed up successfully!\n" << endl;
//			userLogin();
//		}
//	}
//
//    static void printChoice(const int choiceNum, const string choice){
//        cout << "Press " << choiceNum << " to " << choice << endl;
//    }
//
//    static void printLoginOrSignup() {
//        printChoice(1, "Login");
//        printChoice(2, "Signup");
//    }
//
//    static void introduction(){
//        cout << "*********************************************************************" << endl
//             << "\t\t\tWelcome to TickTock Watches" << endl
//             << "*********************************************************************" << endl
//             << "\"\"" << endl;
//
//        printLoginOrSignup();
//        printChoice(3, "Start shopping");
//
//        cout << "Choose a Number: ";
//    }
//	private:
//	static void userLoginOrSignup(){
//        printLoginOrSignup();
//
//		int dec;
//		cin >> dec;
//
//		if(dec == 1) userLogin();
//		else if (dec == 2) userSignup();
//	}
//
//	static void userAddToCart(Product selectedProduct){
//		cout << selectedProduct.getQuantity() << " Left in stock." << endl;
//		cout << "How many do you want? " << endl;
//
//		// Make sure that the user select valid quantity value
//		int wantedQuantity = 1;
//		do{
//			cin >> wantedQuantity;
//			if(wantedQuantity > selectedProduct.getQuantity())
//			cout << "Please Enter a count that is less than " << selectedProduct.getQuantity() << endl;
//		}while(wantedQuantity > selectedProduct.getQuantity());
//
//		if(!user) userLoginOrSignup();
//
//		Cart userCart = user->getUserCart();
//		if (userCart.add_toCart(selectedProduct, wantedQuantity)) {
//			cout << selectedProduct.getName() << " Added to Cart Successfully" << endl;
//		} else cout << "Unknown error adding product to cart" << endl;
//	}
//
//
//	public:
//	static void productsList() {
//		int number = 0;
//
//		do {
//			cout << endl;
//			cout << "Click on the number of the product to show description" << endl;
//			vector<Product> productList = Product::readData();
//			//For loop to display all products from database
//			for (Product product : productList) {
//				cout << product.getId() << ") " << product.getName() << endl;
//			}
//
//			//choosing a number to show the product description
//			cout << "Chose a number ( enter 0 to go back ): " << endl;
//			cin >> number;
//
//			if (number == 0) return;
//
//			//for loop to show the products description
//			Product selectedProduct;
//			for (Product product : productList) {
//				if (number == product.getId()) {
//					selectedProduct = product;
//					cout << "Description: " << product.getDescription() << endl;
//					cout << "Price: " << product.getPrice() << endl;
//					cout << "Quantity: " << product.getQuantity() << endl;
//					cout << "User Rating: " << product.getUserRating() << endl;
//					break;
//				}
//			}
//
//			cout << "\n1. to add to cart" << endl;
//			cout << "2. to continue shopping" << endl;
//			cout << "Chose a number ( enter 0 to go back ): " << endl;
//
//			cin >> number;
//			if(number == 1) userAddToCart(selectedProduct);
//
//		}while(number == 2);
//	}
//	static void loggedIn(){
//		while(true){
//			cout << "\nWhat do you want to do? " << endl;
//            printChoice(1, "Continue shopping");
//            printChoice(2, "Show cart");
//            printChoice(3, "Logout");
//
//			int decision;
//			cin >> decision;
//
//			switch (decision){
//				case 1:
//					productsList();
//					break;
//				case 2:
//					showCart();
//					break;
//				case 3:
//					do {
//						productsList();
//					} while (!user);
//					loggedIn();
//					break;
//			}
//		}
//	}
//};
//
//User* Main::user = nullptr;
//


int main() {
		
	Controller* controller = new Controller();
	User *user = nullptr;
	while (true) {
		ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
		Selection* actionSelect = selectionPool->acquireObject();
		if (user == nullptr) {
			actionSelect->addChoice("Login", bind(&Controller::loginUser, controller, placeholders::_1));
			actionSelect->addChoice("Sign Up", bind(&Controller::signupUser, controller, placeholders::_1));
			actionSelect->addChoice("Shopping", bind(&Controller::shop, controller, placeholders::_1));
			actionSelect->handleUserChoice(&user);
		}
		else {
			controller->loggedInUser(&user);
		}
	}

		/*int decision;
		cin >> decision;

		switch (decision){
			case 1:
				Main::userLogin();
				Main::loggedIn();
				break;
			case 2:
				Main::userSignup();
				Main::loggedIn();
				break;
			case 3:
				do {
					Main::productsList();
				} while (Main::user);
				Main::loggedIn();
				break;
		}*/


}