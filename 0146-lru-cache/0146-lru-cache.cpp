class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<int,list<int>::iterator>>mp;
    int n;
    LRUCache(int capacity) 
    {
        n=capacity;
    }
    
    int get(int key) 
    {
        // first we have to check if the element is availabel 
        // if available we have to make it recently used 
        if(mp.find(key)!=mp.end())
        {
            // it means the element is avialable 
            int val=mp[key].first;
            // now we have to make it recently used 
            // for that we have to erase its erlier position and push it in the front 
            list<int>::iterator it = mp[key].second;
            dll.erase(it);

            dll.push_front(key);
            mp[key].second=dll.begin();
            return val;
        }

        return -1;
        
    }
    
    void put(int key, int value) 
    {
        // first we have to check if the value already present in the lru 
        if(mp.find(key)!=mp.end())
        {
            // it means we have to just update the value and make it recently used 
            mp[key].first=value;

            list<int>::iterator it = mp[key].second;
            dll.erase(it);

            dll.push_front(key);
            mp[key].second=dll.begin();

        }

        else
        {
            // we have to insert a new key
            dll.push_front(key);
            n--;

            // update the map
            mp[key]={value,dll.begin()};
        

        if(n==-1)
        {
            // then we have to delete the element which is least recently used 
            int last=dll.back();
            mp.erase(last);
            dll.pop_back();
            n++;
        }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */