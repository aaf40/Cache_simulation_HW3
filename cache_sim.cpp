function main(argc, argv)
    if argc != 4
        print "Usage: ./cache_sim <num_entries> <associativity> <memory_reference_file>"
        exit

    num_entries = convert_to_integer(argv[1])
    associativity = convert_to_integer(argv[2])
    memory_reference_file = argv[3]

    cache = initialize_cache(num_entries, associativity)
    memory_addresses = read_memory_addresses(memory_reference_file)

    output_file = open_file("cache_sim_output", write)
    for address in memory_addresses
        result = access_cache(cache, address)
        write_output(output_file, address, result)

    close_file(output_file)

function initialize_cache(num_entries, associativity)
    number_of_sets = num_entries / associativity
    cache = new Cache(number_of_sets, associativity)
    for each set in cache.sets
        for i from 0 to associativity
            set[i] = new CacheEntry(invalid, null)
    return cache

function read_memory_addresses(file_path)
    file = open_file(file_path, read)
    content = read_file(file)
    close_file(file)
    return split(content, spaces)

function access_cache(cache, address)
    set_index = calculate_set_index(address, cache.number_of_sets)
    tag = calculate_tag(address)
    set = cache.sets[set_index]

    for entry in set
        if entry.valid and entry.tag == tag
            return "HIT"

    update_cache(set, tag)
    return "MISS"

function calculate_set_index(address, number_of_sets)
    return address mod number_of_sets

function calculate_tag(address)
    return address / number_of_sets  // Simplified example

function update_cache(set, new_tag)
    for entry in set
        if not entry.valid
            entry.tag = new_tag
            entry.valid = true
            return
    set[0].tag = new_tag

function write_output(file, address, result)
    write_line_to_file(file, format("{0} : {1}", address, result))
