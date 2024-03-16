// This class represents a time-based key-value store where each key can have multiple values associated with different timestamps.
class TimeMap
{
public:
    // Map to store keys and their corresponding vector of pairs (value, timestamp).
    unordered_map<string, vector<pair<string, int>>> mp;

    // Constructor for the TimeMap class.
    TimeMap()
    {
        // Constructor implementation is empty.
    }

    // Function to set the value of a key at a given timestamp.
    void set(string key, string value, int timestamp)
    {
        // Access the vector associated with the key in the map and push the pair (value, timestamp) into it.
        mp[key].push_back({value, timestamp});
    }

    // Function to retrieve the value of a key at a given timestamp.
    // Returns an empty string if the key is not found or if the timestamp is not available for that key.
    string get(string key, int timestamp)
    {
        // Check if the key exists in the map.
        if (mp.find(key) != mp.end())
        {
            // Retrieve the vector associated with the key.
            vector<pair<string, int>> &values = mp[key];
            // Iterate through the vector in reverse order (latest timestamp first).
            for (auto it = values.rbegin(); it != values.rend(); it++)
            {
                // If the timestamp of the pair is less than or equal to the given timestamp,
                // return the corresponding value.
                if (it->second <= timestamp)
                {
                    return it->first;
                }
            }
        }
        // Return an empty string if the key is not found or if the timestamp is not available.
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
