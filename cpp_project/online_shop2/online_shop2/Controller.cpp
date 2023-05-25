//
// Created by NoteBook on 23/05/2023.
//

#include "Controller.h"
#include <iostream>
#include <functional>

using namespace std;

Controller::Controller(){
    view = new View();

    model = Model::getInstance();
}

void Controller::handleCart() {
    view->displayProductsInCart(user->getProductsInCart());

    ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
    Selection* actionSelect = selectionPool->acquireObject();
    function<void(User*)> proceedPaymentCallback = bind(&Model::proceedPayment, model, placeholders::_1);
    actionSelect->addChoice("Proceed Payment", proceedPaymentCallback);

    function<void(User*)> removeProductCallback = bind(&Model::removeProductFromCart, model, placeholders::_1);
    actionSelect->addChoice("Remove product from cart", removeProductCallback);
    actionSelect->handleUserChoice(user);
}

