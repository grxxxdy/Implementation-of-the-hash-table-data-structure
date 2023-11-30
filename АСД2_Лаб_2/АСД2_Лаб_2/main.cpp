#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <unordered_map>
#include <list>
#include "LinkedList.h"

using namespace std;


long long generateRandLong() 
{

    long long int result = 0;

    int numbersAmount = 10 + rand() % 6;

    for (int i = 0; i < numbersAmount; i++) 
    {
        result += (1 + rand() % 9) * pow(10, i);
    }

    return result;

}

struct HashTable 
{
    int SIZE = 0;
    float maxLoadFactor = 9, loadFactor;
    int M = 13;
    LinkedList* bucketArray = new LinkedList[M];

    void resize()
    {
        M = M * 2;
        LinkedList* temp = new LinkedList[M];

        for (int i = 0; i < M / 2; i++)
        {
            while (bucketArray[i].size() != 0)
            {
                Element tempElem = bucketArray[i].pop_front();

                temp[hash(tempElem.key)].push_back(&tempElem);
            }
        }
         
        delete[] bucketArray;

        bucketArray = temp;
    }

    int hash(long long int key)
    {
        int index = key % M;

        return index;
    }

    void insert(long long int key, Data value)
    {
        if (findAndReplace(key, value) != nullptr)
        {
            return;
        }

        loadFactor = ((float)size() / M);

        if (loadFactor >= maxLoadFactor)
        {
            resize();
        }
        Element temp = { value, key };

        bucketArray[hash(key)].push_back(&temp);

        SIZE++;
    }

    Element* find(long long int key)
    {
        HashNode* temp = bucketArray[hash(key)].head;

        while (temp != nullptr)
        {
            if (temp->data.key == key)
            {
                return &temp->data;
            }

            temp = temp->nextElement;
        }

        return nullptr;
    }

    void erase(long long int key)
    {
        int index = hash(key);

        HashNode* temp = bucketArray[index].head;
        HashNode* prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->data.key == key)
            {
                if (prev == nullptr)
                {
                    bucketArray[index].pop_front();
                }
                else
                {
                    prev->nextElement = temp->nextElement;
                    delete temp;
                }

                SIZE--;
                return;
            }
            prev = temp;
            temp = temp->nextElement;
        }
    }

    Element* findAndReplace(long long int key, Data& value)
    {
        int index = hash(key);

        HashNode* temp = bucketArray[index].head;

        while (temp != nullptr)
        {
            if (temp->data.key == key)
            {
                temp->data.value = value;
                return &temp->data;
            }

            temp = temp->nextElement;
        }

        return nullptr;
    }

    int size()
    {
        return SIZE;
    }

    ~HashTable()
    {
        delete[] bucketArray;
    }
};

bool testHashTable()
{
    const int iters = 500000;
    const int keysAmount = iters * 1;
    // generate random keys:
    long long* keys = new long long[keysAmount];
    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];
    for (int i = 0; i < keysAmount; i++)
    {
        keys[i] = generateRandLong();
    }
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];
    }
    // test my HashTable:
    HashTable hashTable;
    clock_t myStart = clock();


    clock_t ewq = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.insert(keysToInsert[i], Data());
    }
    int myInsertSize = hashTable.size();
    clock_t dsa = clock();
    float xxxx = (float(dsa - ewq)) / CLOCKS_PER_SEC;
    cout << "Insert: " << xxxx << endl;


    clock_t qwe = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.erase(keysToErase[i]);
    }
    int myEraseSize = hashTable.size();
    clock_t asd = clock();
    float xxx = (float(asd - qwe)) / CLOCKS_PER_SEC;
    cout << "Erase: " << xxx << endl;

    clock_t eee = clock();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (hashTable.find(keysToFind[i]) != NULL)
        {
            myFoundAmount++;
        }
    }
    clock_t aaa = clock();
    float xxxxx = (float(aaa - eee)) / CLOCKS_PER_SEC;
    cout << "Find: " << xxxxx << endl;


    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
    // test STL hash table:
    unordered_map<long long, Data> unorderedMap;
    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({ keysToInsert[i], Data() });
    }
    int stlInsertSize = unorderedMap.size();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    int stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;
    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << " , after insert: " << myInsertSize << " , after erase: " << myEraseSize << ", found: " << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << " , after insert: " << stlInsertSize << " , after erase:" << stlEraseSize << ", found: " << stlFoundAmount << endl << endl;
    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;
    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount ==
        stlFoundAmount)
    {
        cout << "The lab is completed" << endl;
        return true;
    }

    cerr << ":(" << endl;
    return false;
}


int main() {
    srand(time(NULL));

    testHashTable();
}