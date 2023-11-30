#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H
#include "Data.cpp"

struct HashNode
{
    Element data;
    HashNode* nextElement;
};

struct LinkedList
{
    int SIZE;

    HashNode* head;
    HashNode* tail;

    LinkedList();

    void push_front(Element* catt);

    void push_back(Element* catt);

    Element* get(int element);

    Element pop_front();

    Element pop_back();

    int size();

    void print();

    void clear();

    void insert(Element* catt, int element);

    void remove(int element);

    void replace(Data& value, long long int& key);

    ~LinkedList();
};

#endif //UNTITLED_LINKEDLIST_H
