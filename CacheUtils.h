#ifndef CACHE_UTILS_H
#define CACHE_UTILS_H

#include "Cache.h"
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <unordered_map>
#include <algorithm>
//#include <iomanip> // May be useful for formatting if needed

Cache* initialize_cache(int num_entries, int associativity);
std::vector<int> read_memory_addresses(const std::string& file_path);
std::string access_cache(Cache* cache, int address);
void update_cache(std::vector<CacheEntry>& set, int new_tag);
int calculate_set_index(int address, int number_of_sets);
int calculate_tag(int address);
void write_output(std::ofstream& file, int address, const std::string& result);

#endif
