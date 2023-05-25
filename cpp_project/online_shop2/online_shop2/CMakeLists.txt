cmake_minimum_required(VERSION 3.25)
project(online_shop2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(online_shop2
        baseEntity.cpp
        baseEntity.h
        cart.cpp
        cart.h
        db.h
        main.cpp
        payment.cpp
        payment.h
        product.cpp
        product.h
        productInCart.cpp
        productInCart.h
        user.cpp
        user.h Selection.cpp Selection.h View.cpp View.h Controller.cpp Controller.h Model.cpp Model.h trash.cpp ObjectPool.h ObjectPool.cpp Utils.cpp Utils.h)
