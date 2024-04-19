#include "CacheUtils.h"

// Function to initialize cache
Cache* initialize_cache(int num_entries, int associativity) {
    int number_of_sets = num_entries / associativity;
    Cache* cache = new Cache(number_of_sets, associativity);

    for (auto& set : cache->sets) {
        for (auto& entry : set) {
            entry.valid = false;
            entry.tag = -1;  // Initialize tag with -1 indicating it is not valid
        }
    }

    return cache;
}

// Function to read memory addresses from a file and return them as a vector of integers
std::vector<int> read_memory_addresses(const std::string& file_path) {
    std::ifstream file(file_path); 
    std::vector<int> addresses;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return addresses; 
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        int address;
        while (iss >> address) {
            addresses.push_back(address);
        }
    }

    file.close();
    return addresses;
}

// Function to access the cache and determine if it's a hit or miss
std::string access_cache(Cache* cache, int address) {
    int set_index = calculate_set_index(address, cache->number_of_sets);
    int tag = calculate_tag(address);
    auto& set = cache->sets[set_index];

    for (auto& entry : set) {
        if (entry.valid && entry.tag == tag) {
            return "HIT";
        }
    }

    update_cache(set, tag);
    return "MISS";
}

// function to calculate the set index from an address
int calculate_set_index(int address, int number_of_sets) {
    return address % number_of_sets; 
}

// function to calculate the tag from an address
int calculate_tag(int address) {
    return address; 
}

// Function to update the cache when a miss occurs

void update_cache(std::vector<CacheEntry>& set, int new_tag) {
    // Replace the first invalid entry, or replace the first entry if all are valid
    for (auto& entry : set) {
        if (!entry.valid) {
            entry.tag = new_tag;
            entry.valid = true;
            return;
        }
    }

    // Simple replacement policy (could be improved with LRU or another strategy)
    set[0].tag = new_tag;
    set[0].valid = true;
}


// Function to write the output to a file
void write_output(std::ofstream& file, int address, const std::string& result) {
    file << address << " : " << result << std::endl;
    if (!file) {
        std::cerr << "Error writing to file." << std::endl;
    }
}