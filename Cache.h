#ifndef CACHE_H
#define CACHE_H

#include "CacheEntry.h"
#include <vector>

class Cache {
public:
    int number_of_sets;
    int associativity;
    std::vector<std::vector<CacheEntry>> sets;

    Cache(int num_sets, int assoc) : number_of_sets(num_sets), associativity(assoc) {
        sets.resize(number_of_sets, std::vector<CacheEntry>(associativity));
    }
};

#endif
