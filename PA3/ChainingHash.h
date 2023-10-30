/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    vector <list<pair<K, V>>> table;
    int bucketCount;
    int sizeT;
public:
    ChainingHash(int n = 11) {
        this->bucketCount = n;
        this->sizeT = 0;
        table.resize(this->bucketCount);
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return this->sizeT;
    }

    V operator[](const K& key) {
        int index = hash(key) % this->bucketCount;
       
        auto iter = this->table[index].begin();
        for (; iter != this->table[index].end(); iter++) {
            if (iter->first == key) {
                return iter->second;
            }
        }
        return -1;  //If key has no pair, return -1
    }

    bool insert(const std::pair<K, V>& pair) {
        int index = hash(pair.first) % this->bucketCount;       //Hash the key, then take mod of size of vector

        auto iter = this->table[index].begin();
        for (; iter != this->table[index].end(); iter++) {
            if (iter->first == pair.first) {
                iter->second = pair.second;     //If new key already exists in the table, update value of key
                return true;
            }
        }

        this->table[index].push_back(pair);     //Send the key to the end of the list at vector index corresponding to hash
        this->sizeT++;
        if (this->load_factor() >= 0.75) {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        int hashKey = hash(key) % this->bucketCount;
        list<pair<K, V>>& hashList = this->table[hashKey];          //Check whether shallow/copy memory so erase works on table 

        auto iter = hashList.begin();
        for (; iter != hashList.end(); iter++) {
            if (iter->first == key) {
                hashList.erase(iter);       
                this->sizeT--;
                return;
            }
        }
    }

    void clear() {
        for (int i = 0; i < this->bucketCount; i++) {
            this->table[i].clear();         //Erase lists from each vector index
        }
        this->sizeT = 0;
    }

    int bucket_count() {
        return this->bucketCount;
    }

    float load_factor() {
        return ((float)this->sizeT / (float)this->bucketCount);   //Load factor is ratio of number of items in table and vector indexs, big ratio = too many elements for the table = more like linked list = slower
    }

private:
    void rehash() {
        int newBucketCount = findNextPrime(this->bucketCount * 2);
        ChainingHash<K, V> newTable(newBucketCount);
        
        for (int vectorPos = 0; vectorPos < this->bucketCount; vectorPos++) {       //Loop to traverse through vector
            auto iter = this->table[vectorPos].begin();
            for (; iter != this->table[vectorPos].end(); iter++) {      //Loop to traverse through list at each vector index
                newTable.insert(*iter);
            }
        }
        this->clear();

        this->sizeT = newTable.sizeT;   
        this->bucketCount = newTable.bucketCount;       //Clear table and update table with rehashed values
        this->table = newTable.table;

    }

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        std::hash<K> defaultHash;
        int hashValue = abs(int(defaultHash(key)));     //Use default hash function from library
        return hashValue;       
    }

};

#endif //__CHAINING_HASH_H
