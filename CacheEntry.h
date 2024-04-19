#ifndef CACHE_ENTRY_H
#define CACHE_ENTRY_H

#include <list>

class CacheEntry {
public:
    bool valid;
    int* tag;

    CacheEntry() : valid(false), tag(nullptr) {}
};

#endif
