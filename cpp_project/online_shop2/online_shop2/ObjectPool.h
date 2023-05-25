//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_OBJECTPOOL_H
#define ONLINE_SHOP2_OBJECTPOOL_H

#include <vector>

template <class T>
class ObjectPool {
    std::vector<T*> pool;
    static ObjectPool<T>* instance;

    ObjectPool() {}
public:
    T* acquireObject();
    void releaseObject(T* obj);
    static ObjectPool<T>* getInstance();
};


#endif //ONLINE_SHOP2_OBJECTPOOL_H
