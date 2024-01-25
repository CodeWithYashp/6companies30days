class LRUCache {
private:
    unordered_map<int, list<pair <int, int>>::iterator> hashmap;

    list<pair<int, int>> cache;

    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto a = hashmap.find(key);
        if(a != hashmap.end()){
            cache.splice(cache.end(), cache, a->second);
            return a->second->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto a = hashmap.find(key);         
        
        if (a != hashmap.end()) {          
            cache.splice(cache.end(), cache, a->second);    
            a->second->second = value;
            return;
        }
        
        if (hashmap.size() >= cap) {  
    		hashmap.erase(hashmap.find(cache.begin()->first));
                                            
		    cache.pop_front();                
        }
        
        pair<int, int> res = { key, value };  
        cache.push_back(res);                 
	    list <pair<int, int>>::iterator cachei = cache.end(); cachei--;
        hashmap[cachei->first] = cachei;        
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */