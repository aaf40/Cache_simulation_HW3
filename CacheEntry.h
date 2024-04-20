#ifndef CACHE_ENTRY_H
#define CACHE_ENTRY_H

#include <list>

class CacheEntry {
public:
    bool valid;
    int tag;  
    int lastUsed;

    CacheEntry() : valid(false), tag(-1), lastUsed(0) { }
};

#endif
