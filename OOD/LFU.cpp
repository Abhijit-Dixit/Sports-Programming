/*
1) get
    If key is not in "cache" return -1;
    Else update key's frequency in "cache" & "freqMap", and then return value from "cache".
        To update a key:-
                1) fetch the frequency of key from "cache" and increment its frequency in "cache"
                2) fetch the iterator for the current key
                3) erase the key from "freqMap" and add the key to increased frequency list in "freqMap"
                4) update "listItrMap" to store new iterator for key
                5) if no keys have minFreq than erase "minFreq" from "freqMap" and increment "minFreq"
2) put
    
*/


class LFUCache {
    
private:
    int capacity;
    unordered_map<int, pair<int,int>> cache; // {key -> pair of value and frequency} mapping
    unordered_map<int, list<int>::iterator> listItrMap; // {key -> iterator} mapping
    unordered_map<int,list<int>> freqMap; // {freq -> linked list of keys ordered according to recency} mapping
    int minFreq=0; // min frequency among all the keys currenty in Cache.
    
    void updateFrequency(int key){
        int freq = cache[key].second;
        cache[key].second++;
        freqMap[freq].erase(listItrMap[key]);
        freqMap[freq+1].push_front(key);
        listItrMap[key] = freqMap[freq+1].begin();
        if(freqMap[minFreq].size()==0 ){
           freqMap.erase(minFreq);
            minFreq++;
        }
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())
            return -1;
        
        updateFrequency(key);         
        return cache[key].first;
    }
    
    void put(int key, int value){
        
        if(cache.count(key)){
            updateFrequency(key);            
            cache[key].first = value; //update value in cache
        }
        else{
            if(cache.size() >= this->capacity){
                int leastFrequentKey = freqMap[minFreq].back();
                cache.erase(leastFrequentKey);
                listItrMap.erase(leastFrequentKey);
                freqMap[minFreq].pop_back();
            } 
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            listItrMap[key] = freqMap[0].begin();            
            minFreq=0;
        }
    }
};
