class Solution {
public:
    using ll=long long;
    long long beautifulSubarrays(vector<int>& nums) 
    {
        ll count=0;
        unordered_map<int,ll>mp;

        int pref=0;
        mp[0]=1;

        for(int i=0;i<nums.size();i++)
        {
            pref^=nums[i];

            if(mp.find(pref)!=mp.end())
            {
                count=count+mp[pref];
            }
            mp[pref]++;
        }

        return count;

    }
};