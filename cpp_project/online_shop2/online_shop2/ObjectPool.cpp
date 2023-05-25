#include "ObjectPool.h"

template <typename T>
T* ObjectPool<T>::acquireObject() {
    if (pool.empty()) {
        T* obj = new T();
        obj->initialize();
        return obj;
    }
    else {
        T* obj = pool.back();
        pool.pop_back();
        obj->reset();
        return obj;
    }
}

template <typename T>
void ObjectPool<T>::releaseObject(T* obj) {
    pool.push_back(obj);
}

template <typename T>
ObjectPool<T>* ObjectPool<T>::getInstance(){
    if (instance == nullptr)
    {
        instance = new ObjectPool<T>;
    }
    return instance;
}

template <typename T>
ObjectPool<T>* ObjectPool<T>::instance = nullptr;

