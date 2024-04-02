class LRUCache
{
public:
    list<int> dll;                                            // Doubly linked list to maintain the order of keys
    unordered_map<int, pair<list<int>::iterator, int>> cache; // Hashmap to store key-value pairs along with their corresponding iterator in the doubly linked list
    int n;                                                    // Capacity of the cache

    // Constructor to initialize the cache with given capacity
    LRUCache(int capacity)
    {
        this->n = capacity;
    }

    // Function to update the position of a key in the doubly linked list to denote recent usage
    void makeRecentlyUsed(int key)
    {
        dll.erase(cache[key].first);    // Erase the iterator of the key from its current position in the list
        dll.push_front(key);            // Push the key to the front of the list to denote recent usage
        cache[key].first = dll.begin(); // Update the iterator of the key in the cache map
    }

    // Function to retrieve the value associated with a key from the cache
    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {                             // If the key is found in the cache
            makeRecentlyUsed(key);    // Update its position in the doubly linked list
            return cache[key].second; // Return the value associated with the key
        }
        return -1; // Return -1 if the key is not found in the cache
    }

    // Function to insert or update a key-value pair in the cache
    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {                              // If the key already exists in the cache
            cache[key].second = value; // Update its value
            makeRecentlyUsed(key);     // Update its position in the doubly linked list
        }
        else
        {                                      // If the key is not present in the cache
            dll.push_front(key);               // Insert the key at the front of the doubly linked list
            cache[key] = {dll.begin(), value}; // Update the cache map with the key-value pair and its iterator in the list
            n--;                               // Decrement the remaining capacity of the cache
        }

        if (n < 0)
        {                                    // If the cache capacity is exceeded
            int keyToBeDeleted = dll.back(); // Get the key to be deleted (least recently used)
            cache.erase(keyToBeDeleted);     // Erase the key from the cache map
            dll.pop_back();                  // Remove the key from the end of the doubly linked list
            n++;                             // Increment the remaining capacity of the cache
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
