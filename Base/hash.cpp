//
// Created by Messi on 2023/12/16.
//

#include "hash.h"

void MyHashMap::put(int key, int value) {
    int keyHash = hash(key);
    if (hashMap[keyHash] == nullptr)
        hashMap[keyHash] = new map(key, value);
    else {
        if (hashMap[keyHash]->key == key) {
            hashMap[keyHash]->value = value; //更新
            return;
        }
        /*1*/
        auto p = hashMap[keyHash]->next;
        while (p != nullptr) {
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }
        /*1这种写法,最后新添加的节点，没有接上去，因为最后一次遍历之后p指针指向最后一个节点的next
        也就是nullptr，并不指向某个地址，需要第二种写法添加链表节点*/
        p = new map(key, value);

        /*2*/
        /*
        auto p = hashMap[keyHash];
        while (p->next) {
            if (p->next->key == key) {
                p->next->value = value;
                return;
            }
            p = p->next;
        }
        p->next = new map(key, value);
        */
    }
}

int MyHashMap::get(int key) {
    int keyHash = hash(key);
    if (hashMap[keyHash] == nullptr)
        return -1;
    auto p = hashMap[keyHash];
    if (p->key == key)
        return p->value;
    while (p->next) {
        if (p->next->key == key)
            return p->next->value;
        p = p->next;
    }
    return -1;
}

void MyHashMap::remove(int key) {
    int keyHash = hash(key);
    if (hashMap[keyHash] == nullptr)
        return;
    auto p = hashMap[keyHash];
    if (p->key == key) {
        hashMap[keyHash] = p->next;
        delete p;
        return;
    }
    auto next = p->next;
    while (next) {
        if (next->key == key) {
            p->next = next->next;
            delete next;
            return;
        }
        p = next;
        next = next->next;
    }
}
