//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_CONTROLLER_H
#define ONLINE_SHOP2_CONTROLLER_H

//#include "View.h"
//#include "user.h"
//#include "Selection.h"
#include "Model.h"

class Controller {
    User* user;
    View* view;
    Model* model;
public:
    Controller();

    void handleCart();
};


#endif //ONLINE_SHOP2_CONTROLLER_H
