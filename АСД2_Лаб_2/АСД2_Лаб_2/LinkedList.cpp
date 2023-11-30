#include <iostream>
#include "LinkedList.h"

using namespace std;

int SIZE;

HashNode* head;
HashNode* tail;

LinkedList::LinkedList()
{
    SIZE = 0;
    head = nullptr;
    tail = nullptr;
}

void LinkedList::push_front(Element* catt)
{
    HashNode* newNode = new HashNode();

    newNode->data = (*catt);

    if (!head)
    {
        tail = newNode;
        newNode->nextElement = nullptr;
    }
    else
    {
        newNode->nextElement = head;
    }

    head = newNode;

    SIZE++;
}

void LinkedList::push_back(Element* catt)
{
    HashNode* newNode = new HashNode();

    newNode->data = (*catt);

    newNode->nextElement = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        tail->nextElement = newNode;
    }

    tail = newNode;

    SIZE++;

}

Element* LinkedList::get(int element)
{
    if (!head)
    {
        return nullptr;
    }

    if (element < 0)
    {
        return nullptr;
    }
    HashNode* current = head;

    for (int i = 0; i < element; i++)
    {
        if (current->nextElement == nullptr)
        {
            return nullptr;
        }
        current = current->nextElement;
    }

    return &current->data;

}

Element LinkedList::pop_front()
{
    Element tempElement;

    if (!head)
    {
        throw out_of_range("no elements");
    }

    tempElement = head->data;

    if (head == tail)
    {
        delete head;

        head = nullptr;
        tail = nullptr;
        SIZE--;

        return tempElement;
    }

    HashNode* temp = head->nextElement;

    delete head;

    head = temp;

    SIZE--;

    return tempElement;
}

Element LinkedList::pop_back()
{
    Element tempElement;

    if (!head)
    {
        throw out_of_range("no elements");
    }

    tempElement = tail->data;

    if (head == tail)
    {
        delete head;

        head = nullptr;
        tail = nullptr;
        SIZE--;

        return tempElement;
    }

    HashNode* current = head;

    /*while (current->nextElement != tail)
    {
        current = current->nextElement;
    }

    delete tail;

    current->nextElement = nullptr;

    tail = current;*/

    while (current->nextElement && current->nextElement->nextElement && current->nextElement->nextElement->nextElement)
    {
        current = current->nextElement->nextElement;
    }

    if (current->nextElement->nextElement == tail)
    {
        current = current->nextElement;
    }

    delete tail;

    current->nextElement = nullptr;

    tail = current;

    SIZE--;

    return tempElement;
}

int LinkedList::size()
{
    /*int amount = 0;

    HashNode* current = head;

    while (current != nullptr )
    {
        current = current->nextElement;
        amount++;
    }*/

    return SIZE;
}

void LinkedList::print()
{
    if (!head)
    {
        cout << "Cписок порожній" << endl;
        return;
    }

    HashNode* current = head;
    int i = 1;

    while (current != nullptr)
    {
        cout << "Ім'я: " << current->data.value.name << endl;
        cout << "Предмет: " << current->data.value.subject << endl;
        cout << "Якість мікрофону: " << current->data.value.micQuality << "%\n" << endl;

        current = current->nextElement;
        i++;
    }

}

void LinkedList::clear()
{
    HashNode* current = head;

    while (head != nullptr)
    {
        current = head->nextElement;

        delete head;

        head = current;
    }

    tail = nullptr;
}

void LinkedList::insert(Element* catt, int element)
{
    if (element < 0)
    {
        cout << "Error" << endl;
        return;
    }
    else if (element == 0)
    {
        push_front(&*catt);
        return;
    }

    HashNode* current = head;
    HashNode* previous = nullptr;

    for (int i = 0; i < element; i++)
    {
        if (current->nextElement == nullptr)
        {
            push_back(catt);
            return;
        }

        previous = current;

        current = current->nextElement;
    }

    HashNode* newNode = new HashNode();

    newNode->data = (*catt);

    previous->nextElement = newNode;
    newNode->nextElement = current;

    SIZE++;

}

void LinkedList::remove(int element)
{
    if (element < 0)
    {
        //        cout << "Елемента з таким номером немає у списку" << endl;
        return;
    }
    else if (element == 0)
    {
        pop_front();
        return;
    }

    HashNode* current = head;
    HashNode* previous = nullptr;

    for (int i = 0; i < element; i++)
    {
        if (current->nextElement == nullptr)
        {
            //            cout << "Елемента з таким номером немає у списку" << endl;
            return;
        }

        previous = current;

        current = current->nextElement;
    }

    previous->nextElement = current->nextElement;

    delete current;

    SIZE--;
}

void LinkedList::replace(Data& value, long long int& KEY)
{
    HashNode* current = head;

    while (current != nullptr)
    {
        if (current->data.key == KEY)
        {
            current->data.value = value;
            return;
        }

        current = current->nextElement;
    }
}

LinkedList::~LinkedList()
{
    clear();
}