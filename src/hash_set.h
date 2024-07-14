//
// Created by diegorandolp on 15/06/24.
//

#ifndef PROYECTOFINAL_HASH_SET_H
#define PROYECTOFINAL_HASH_SET_H

#include <iostream>
#include <vector>

using namespace std;

const int maxColision = 3;

template <typename TK, typename TV>
class HashTable;
//itera sobre el hashtable manteniendo el orden de insercion
template <typename TK, typename TV>
class HashIterator
{
private:
    typedef typename HashTable<TK, TV>::Node* NodePtr;
    NodePtr nodePtr;

public:
    HashIterator(NodePtr ptr = nullptr): nodePtr(ptr){}
    HashIterator<TK, TV> &operator=(const HashIterator& other){
        if (this != &other){
            nodePtr = other.nodePtr;
        }

        return *this;
    }
    bool operator!=(const HashIterator& other)const{
        return nodePtr != other.nodePtr;
    }
    HashIterator<TK, TV> &operator++(){
        if (nodePtr != nullptr){
            nodePtr = nodePtr->nextInsert;
        }
        return *this;
    }   //++it
    TV& operator*(){
        if (!nodePtr) throw out_of_range("Dereferencing null pointer");
        return nodePtr->value;
    }
};

template <typename TK, typename TV>
class HashTable
{
public:
    typedef HashIterator<TK, TV>  iterator;
    iterator begin(){
        return iterator(head);
    };// Retorna el inicio del iterador
    iterator end(){
        return iterator(nullptr);
    };// Retorna el final del iterador

private:
    struct Node {
        TK key;
        TV value;
        Node* next;
        Node* prev;
        Node* nextInsert;

        Node(TK key, TV value): key(key), value(value), next(nullptr), prev(nullptr), nextInsert(nullptr) {}
    };
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** array;

    friend class HashIterator<TK, TV>;

//    int hash(TK key){
//        return key;
//    }

public:
    HashTable(int _cap=5): capacity(_cap), size(0){
        head = nullptr;
        tail = nullptr;
        array = new Node*[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = nullptr;
    }

    ~HashTable(){
//        for (int i = 0; i < capacity; i++){
        if (size > 0){
            Node *current = head;
            while (current != nullptr) {
                Node *next = current->nextInsert;
//                cout << current->key << " " << current->value << endl;
                delete current;
                current = next;
            }
        }
//        }
        delete[] array;
    }
    void insert(TK key, TV value){
        hash<TK> hash;
        int index = hash(key) % capacity;
//        cout << "insert: " << key << " index: " << index << endl;
        Node* newNode = new Node(key, value);

        if (head == nullptr){

            head = newNode;
            tail = newNode;
//            cout << "Insert: "<< newNode->key << endl;
        }
        else{
            tail->nextInsert = newNode;
            newNode->prev = tail;
            tail = newNode;
//            cout << "Insert: "<< newNode->key << endl;
        }

//        if (array[index] == nullptr){
        newNode->next = array[index];
//        }
        array[index] = newNode;
        size++;
        int countcol = 0;
        auto current = array[index];
        while(current){
            countcol++;
            current = current->next;
        }
        if (countcol > maxColision) rehashing();
    }
    void insert(pair<TK, TV> item){
        insert(item.first, item.second);
//        cout << "insert: " << item.first << " " << item.second << endl;
    }
    TV& at(TK key){
        hash<TK> hash;
        int index = hash(key)%capacity;
        Node* current = array[index];
        while (current != nullptr){
            if (current->key == key) return current->value;
            current = current->next;
        }
        throw out_of_range("Key not found");
    }
    TV& operator[](TK key){
        try{
            return at(key);
        }catch(const out_of_range&){
            insert(key, TV());
            return at(key);
        }
    }
    bool find(TK key){
        hash<TK> hash;
        int index = hash(key) % capacity;
//        cout << "find: " << hash(key);
        Node* current = array[index];

        while (current){
//            cout << "find " << current->key << "index: " << index << endl;
            if (current->key == key) return true;
            current = current->next;
        }
        return false;
    }
    bool remove(TK key){
        hash<TK> hash;
        int index = hash(key)%capacity;
        Node* current = array[index];
        Node* prev = nullptr;

        while (current != nullptr){
            if (current->key == key){
                if (prev == nullptr){
                    array[index] = current->next;
                }else{
                    prev->next = current->next;
                }
                if (current->prev){
                    current->prev->nextInsert = current->nextInsert;
                }
                if (current->nextInsert){
                    current->nextInsert->prev = current->prev;
                }
                if (current == head) {
                    head = current->nextInsert;
                }
                if (current == tail) {
                    tail = current->prev;
                }
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    int getSize()const{
        return size;
    }

    /*itera sobre el hashtable manteniendo el orden de insercion*/
    vector<TK> getAllKeys()const{
        vector<TK> keys;
        Node* current = head;
        while (current != nullptr){
            keys.push_back(current->key);
            current = current->nextInsert;
        }
        return keys;
    }
    vector<pair<TK, TV>> getAllElements()const{
        vector<pair<TK, TV>> elements;
        Node* current = head;
        while (current != nullptr){
            elements.emplace_back(current->key, current->value);
            current = current->nextInsert;
        }
        return elements;
    }
private:
    /*Si una lista colisionada excede maxColision, redimensionar el array*/
    void rehashing(){
        int newCapacity = capacity*2;
        Node** newArray = new Node*[newCapacity];
        for (int i = 0; i < newCapacity; i++){
            newArray[i] = nullptr;
        }
        Node* current = head;
        while (current != nullptr){
            hash<TK> hash;
            int index = hash(current->key) % newCapacity;
            if (newArray[index] == nullptr){
                current->next = newArray[index];
            }
            newArray[index] = current;

            current = current->nextInsert;
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
};

template <typename TK>
class HashSet{
private:
    HashTable<TK, TK>* hashTable;
public:
    HashSet(){
        hashTable = new HashTable<TK, TK>();
    }
    typedef HashIterator<TK, TK> iterator;
    iterator begin(){
        return iterator(hashTable->begin());
    }
    iterator end(){
        return iterator();
    }
    void insert(TK key){
        hashTable->insert(key, key);
    }
    bool find(TK key){
        return hashTable->find(key);
    }
    bool remove(TK key){
        return hashTable->remove(key);
    }
    int size(){
        return hashTable->getSize();
    }
    HashSet* unionSet(HashSet* otherSet){
        HashSet* newSet = new HashSet();

        auto inicio1 = begin();
        auto fin1 = end();
        auto inicio2 = otherSet->begin();
        auto fin2 = otherSet->end();

        for (auto i = inicio1; i != fin1 ; ++i) {
            newSet->insert(*i);
        }
        for (auto i = inicio2; i != fin2 ; ++i) {
            newSet->insert(*i);
        }
        return newSet;
    }
    HashSet* intersection(HashSet* otherSet){
        bool thisIsTheMinSet = this->size() < otherSet->size();
        HashSet* newSet = new HashSet();
        if (thisIsTheMinSet){
            auto inicio = begin();
            auto fin = end();
            for (auto i = inicio; i != fin ; ++i) {
                if (otherSet->find(*i)){
                    newSet->insert(*i);
                }
            }
        } else{
            auto inicio = otherSet->begin();
            auto fin = otherSet->end();
            for (auto i = inicio; i != fin ; ++i) {
                if (this->find(*i)){
                    newSet->insert(*i);
                }
            }
        }
        return newSet;
    }
    HashSet* difference(HashSet* otherSet){
        HashSet* newSet = new HashSet();
        auto inicio = begin();
        auto fin = end();
        for (auto i = inicio; i != fin ; ++i) {
            if (!otherSet->find(*i)){
                newSet->insert(*i);
            }
        }
        return newSet;
    }
    void clearSet(){
        auto inicio = begin();
        auto fin = end();
        for (auto i = inicio; i != fin ; ++i) {
            remove(*i);
        }
    }
    void display(){
        auto inicio = begin();
        auto fin = end();
        for (auto i = inicio; i != fin ; ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }
    ~HashSet(){
        delete hashTable;
    }
};



#endif //PROYECTOFINAL_HASH_SET_H

