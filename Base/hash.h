//
// Created by Messi on 2023/12/16.
//

#ifndef ALGORITHM_HASH_H
#define ALGORITHM_HASH_H


#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
    struct map {
        int key;
        int value;
        struct map *next;

        map(int K, int V) : key(K), value(V), next(nullptr) {}
    };

public:
    MyHashMap() {
        hashMap.resize(len);
    }
    void put(int key, int value);
    int get(int key);
    void remove(int key);

private:
    int hash(int key) {
        return (key % len);
    }

    int len = 31;
    vector<struct map *> hashMap;
};


#endif //ALGORITHM_HASH_H
