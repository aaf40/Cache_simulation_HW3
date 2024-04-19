class CacheEntry {
public:
    bool valid;
    int tag;  // Using pointer to int for tag to easily represent null (invalid)

    // Constructor to initialize cache entry
    CacheEntry() : valid(false), tag(-1) { }
};