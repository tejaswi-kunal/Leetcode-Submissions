class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>mp;
    int s;
    RandomizedSet() 
    {
        s=0;
    }
    
    bool insert(int val) 
    {
        if(mp.find(val)!=mp.end())
        {
            return false;
        }

        if(s==nums.size())
        {
            nums.push_back(val);
            mp[val]=nums.size()-1;
            s++;
        }

        else
        {
            nums[s]=val;
            mp[val]=s;
            s++;
        }

        return true;
        
    }
    
    bool remove(int val) 
    {
        if(mp.find(val)!=mp.end())
        {
            int idx=mp[val];

            mp[nums[s-1]]=idx;
            swap(nums[idx],nums[s-1]);
            s--;
            mp.erase(val);

            return true;
        }
        return false;
    }
    
    int getRandom() 
    {
        int idx=rand()%s;
        return nums[idx];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */