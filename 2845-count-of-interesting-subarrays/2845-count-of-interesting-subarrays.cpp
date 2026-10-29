class Solution {
public:
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) 
    {
        ll count=0;
        ll pref=0;
        unordered_map<int,ll>mp;

        mp[0]=1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%m==k)
            {
                pref++;
            }

            pref%=m;

            int val=((pref-k)%m+m)%m;

            if(mp.count(val))
            {
                count+=mp[val];
            }

            mp[pref]++;
        }
        
        return count;
    }
};