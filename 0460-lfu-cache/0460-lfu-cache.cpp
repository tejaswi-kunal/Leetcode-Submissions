class LFUCache {
public:
    // to keep the keys in inc --> dec freq order
    list<int>dll;

    // to keep value,address of key,count
    unordered_map<int,pair<int,pair<list<int>::iterator,int>>>mp;

    // to keep the address of node with recently freq used for a count
    unordered_map<int,list<int>::iterator>count;

    // capacity of the lfu
    int n;
    LFUCache(int capacity) 
    {
        n=capacity;    
    }
    
    int get(int key) 
    {
        // first we have to check if the key is present 
        if(mp.find(key)!=mp.end())
        {
            int val=mp[key].first;
            list<int>::iterator it=mp[key].second.first;
            int c=mp[key].second.second;

            // now we have to increase its freq and mark it as recently used 

            // erase the old one
            // we first have to check if this key was the anchor key or the most recent key for its count only then
            // we will update it count 
            bool isAnchor=0;

            if(count.find(c)!=count.end() && count[c]==it)
            {
                isAnchor=1;
            }
                
            if(isAnchor)
            {
                list<int>::iterator it2=next(it);

                if(it2!=dll.end() && mp[*it2].second.second==c)
                {
                    count[c]=it2;
                }

                else
                {
                    count.erase(c);
                }
            }

            // insert it at new pos
            c++;
            if(count.find(c)!=count.end())
            {
                list<int>::iterator it3=count[c];
                list<int>::iterator it4=dll.insert(it3,key);
                dll.erase(it);
                count[c]=it4;

                mp[key]={val,{it4,c}};
            }

            else
            {
                if (isAnchor)
                {
                    // already sitting at the correct boundary — no move needed
                    count[c]=it;
                    mp[key]={val,{it,c}};
                }
                else
                {
                    // not the anchor -> must physically move to the front of what's
                    // left of the old (c-1) block; count[c-1] is still valid here
                    // since we only touch/erase it inside the isAnchor branch above
                    list<int>::iterator oldAnchor = count[c-1];
                    list<int>::iterator it4 = dll.insert(oldAnchor, key);
                    dll.erase(it);
                    count[c] = it4;
                    mp[key] = {val, {it4, c}};   // {value,...} in put()
                }
            }

            return val;
            
        }

        return -1;
        
    }
    
    void put(int key, int value) 
    {
        // if the key is already present 
        if(mp.find(key)!=mp.end())
        {
            list<int>::iterator it=mp[key].second.first;
            int c=mp[key].second.second;

            // now we have to increase its freq and mark it as recently used 

            // erase the old one
            bool isAnchor=0;

            if(count.find(c)!=count.end() && count[c]==it)
            {
                isAnchor=1;
            }
                
            if(isAnchor)
            {
                list<int>::iterator it2=next(it);

                if(it2!=dll.end() && mp[*it2].second.second==c)
                {
                    count[c]=it2;
                }

                else
                {
                    count.erase(c);
                }
            }

            // insert it at new pos
            c++;
            if(count.find(c)!=count.end())
            {
                list<int>::iterator it3=count[c];
                list<int>::iterator it4=dll.insert(it3,key);
                dll.erase(it);
                count[c]=it4;

                mp[key]={value,{it4,c}};
            }

            else
            {
                if (isAnchor)
                {
                    // already sitting at the correct boundary — no move needed
                    count[c]=it;
                    mp[key]={value,{it,c}};
                }
                else
                {
                    // not the anchor -> must physically move to the front of what's
                    // left of the old (c-1) block; count[c-1] is still valid here
                    // since we only touch/erase it inside the isAnchor branch above
                    list<int>::iterator oldAnchor = count[c-1];
                    list<int>::iterator it4 = dll.insert(oldAnchor, key);
                    dll.erase(it);
                    count[c] = it4;
                    mp[key] = {value, {it4, c}};   // {value,...} in put()
                }
            }
        } 

        else
        {
            // its a new key 
            if(n==0)
            {
                // it means we have no capacity 
                int key2=dll.back();
                int c=mp[key2].second.second;

                mp.erase(key2);

                if(count.find(c)!=count.end() && count[c]==prev(dll.end()))
                {
                    count.erase(c);
                }

                dll.pop_back();
                n++;
            }

            // so now we have to insert the new key at correct pos
            if(count.find(1)!=count.end())
            {
                auto it=count[1];
                auto it2=dll.insert(it,key);
                mp[key]={value,{it2,1}};
                count[1]=it2;
            }

            else
            {
                dll.push_back(key);
                auto it = prev(dll.end());

                mp[key] = {value, {it, 1}};
                count[1] = it;
            }
            n--;
        } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */