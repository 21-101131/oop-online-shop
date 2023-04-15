CREATE DATABASE 'sql8612103';

USE 'sql8612103';

CREATE TABLE Cart(
	id INT AUTO_INCREMENT PRIMARY KEY 
);

CREATE TABLE Products(
	id INT AUTO_INCREMENT PRIMARY KEY ,
	name VARCHAR(255) NOT NULL,
	description VARCHAR(500),
	price FLOAT NOT NULL,
	quantity INT NOT NULL,
	userRating FLOAT
);

CREATE TABLE User (
	id INT AUTO_INCREMENT ,
	name VARCHAR (200) NOT NULL ,
	pass VARCHAR (200) NOT NULL ,
	email VARCHAR (200) NOT NULL ,
	userAdress VARCHAR (200) NOT NULL ,
	creditCardNumber VARCHAR (16) NOT NULL,
	cartId INT NOT NULL ,
	PRIMARY KEY (id),
	FOREIGN KEY (cartId) REFERENCES Cart(id)
);

CREATE TABLE ProductInCart(
	id INT AUTO_INCREMENT PRIMARY KEY ,
	cartId INT NOT NULL,
	productId INT NOT NULL,
	count INT DEFAULT 1 NOT NULL,
	FOREIGN KEY (productId) REFERENCES Products(id),
	FOREIGN KEY (cartId) REFERENCES Cart(id)
);

CREATE TABLE Payment(
	id INT AUTO_INCREMENT PRIMARY KEY,
	value FLOAT NOT NULL,
	userId INT NOT NULL,
	FOREIGN KEY (userId) REFERENCES User(id)
);

