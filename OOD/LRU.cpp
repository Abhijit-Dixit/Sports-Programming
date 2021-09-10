/*
The 2 main functions:-
1) get 
    If key is not in the cache return -1.
    Else update key's recency in "recent" and return value from "cache"
         To update a key:-
                1) fetch its iterator from "pos"
                2) erase the key from its current position with the help of iterator
                3) push the key to front of "recent"
                4) update its position in "pos"

2) put
    Update the key,
        If key is already present in Cache the simply update its recency as shown in the case of get.
        Else If "recent" size is equal to capacity delete the least recently used.
            1) get lru element from recent.back()
            2) remove it from "recent"
            3) remove it from "pos"
            4) remove it from "cache"
        Finally after these conditionals
            1) add key to the front of "recent"
            2) update is iterator in "pos"
    Update the value of the key, in "cache"
*/

class LRUCache {
private:
    int capacity;
    list<int> recent; // linked list of keys ordered according to recency.
    unordered_map<int, int> cache; // key -> value mapping
    unordered_map<int, list<int>::iterator> pos; // key -> iterator mapping
    void update(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
public:
    LRUCache(int capacity): capacity(capacity) {}
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            update(key);
            return cache[key];
        }
        return -1;
    }
    void put(int key, int value) {
        update(key);
        cache[key] = value;
    }
};
