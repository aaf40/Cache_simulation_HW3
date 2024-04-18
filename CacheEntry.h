#ifndef CACHE_ENTRY_H
#define CACHE_ENTRY_H

#include <list>

class CacheEntry {
public:
    bool valid;
    int* tag;
    std::list<int>::iterator lru_iterator;
    std::list<int>::iterator position;
    unsigned long lastUsed;

    CacheEntry() : valid(false), tag(nullptr) {}
};

#endif
