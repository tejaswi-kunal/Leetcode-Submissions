class Solution {
public:
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) 
    {
        ll count=0;

        // it will keep the count of number of elements 0..R for which nums[i]%m==k
        ll pref=0;
        unordered_map<int,ll>mp;
        mp[0]=1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%m==k)
            {
                pref++;
            }

            int x=pref%m;
            int toFind=((x-k)%m+m)%m;
            if(mp.find(toFind)!=mp.end())
            {
                count+=mp[toFind];
            }

            mp[x]++;
        }

        return count;

    }
};