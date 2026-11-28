class Solution {
public:
    using ll=long long;
    long long beautifulSubarrays(vector<int>& nums) 
    {
        ll count = 0;
        unordered_map<int,ll>mp;

        mp[0]=1;
        int R=0;
        for(int i=0;i<nums.size();i++)
        {
            R^=nums[i];

            if(mp.find(R)!=mp.end())
            {
                count+=mp[R];
            }
            mp[R]++;
        }

        return count;
        
    }
};