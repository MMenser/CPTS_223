#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<EntryState, pair<K,V>>> table;
    int bucketCount;
    int sizeT;

public:
    ProbingHash(int n = 11) {
        this->bucketCount = n;
        this->sizeT = 0;
        this->table.resize(n);
        for (int i = 0; i < this->bucketCount; i++) {
            this->table[i].first = EMPTY;
        }
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->sizeT;
    }

    V operator[](const K& key) {
        int index = hash(key) % this->bucketCount;
        int count = 0;

        while (count != this->bucketCount) {
            if (this->table[index].first == VALID && this->table[index].second.first == key) {     
                return this->table[index].second.second;
            }
            index = (index + 1) % this->bucketCount;
            count++;
        }

        return -1;
    }

    bool insert(const std::pair<K, V>& pair) {
        int index = hash(pair.first) % this->bucketCount;
        int count = 0;
        while (count != this->bucketCount) {
            if (this->table[index].second.first == pair.first && this->table[index].first == VALID) {        //Key is equal and position has been filled already - update info
                this->table[index].second = pair;
                return true;
            }

            if (this->table[index].first != VALID) {        //If index is empty/deleted, break out of while loop to insert key here
                break;
            }
            index = (index + 1) % this->bucketCount;        //Update index to look for next available bucket - property of probing hash
            count++;
        }

        if (count == this->bucketCount) {   //If no available space in current table size
            rehash();
        }

        this->sizeT++;
        this->table[index].first = VALID;
        this->table[index].second = pair;

        if (this->load_factor() >= 0.75) {
            rehash();
        }

        return true;
    }

    void erase(const K& key) {
        int index = hash(key) % this->bucketCount;
        int count = 0;
        while (count != this->bucketCount) {
            if (this->table[index].first == VALID && this->table[index].second.first == key) {      //Position is valid and key == key, delete position (not rlly delete, just allow position to take new value via insert)
                this->table[index].first = DELETED;
                this->sizeT--;
                return;
            }
            index = (index + 1) % this->bucketCount;
            count++;
        }
        
    }

    void clear() {
        for (int i = 0; i < this->bucketCount; i++) {
            this->table[i].first = VALID;
        }
        this->sizeT = 0;
    }

    int bucket_count() {
        return this->bucketCount;
    }

    float load_factor() {
        return ((float)this->sizeT / (float)this->bucketCount);
    }

private:
    void rehash() {
        int newBucketCount = findNextPrime(this->bucketCount * 2);
        ProbingHash<K, V> newTable(newBucketCount);

        for (int vectorPos = 0; vectorPos < this->bucketCount; vectorPos++) {       //Loop to traverse through vector
            if (this->table[vectorPos].first == VALID) {        
                newTable.insert(this->table[vectorPos].second);     //Duplicate table into new talbe
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

#endif //__PROBING_HASH_H
