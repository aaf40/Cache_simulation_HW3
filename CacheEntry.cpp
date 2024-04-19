class CacheEntry {
public:
    bool valid;
    int tag; 

    CacheEntry() : valid(false), tag(-1) { }
};