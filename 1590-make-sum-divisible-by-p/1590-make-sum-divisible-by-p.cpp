class Solution {
public:
    using ll = long long;
    int minSubarray(vector<int>& nums, int p) 
    {
        ll totalSum=accumulate(nums.begin(),nums.end(),1LL*0);
        int k=totalSum%p;

        if(k==0)
        {
            return 0;
        }

        int ans=1e8;
        ll pref=0;
        unordered_map<int,int>mp;

        mp[0]=-1;

        for(int i=0;i<nums.size();i++)
        {
            pref=pref+nums[i];
            pref%=p;

            ll val=(pref-k+p)%p;

            if(mp.count(val))
            {
                ans=min(ans,i-mp[val]);
            }
            mp[pref]=i;
        }

        if(ans!=1e8 && ans!=nums.size())
        return ans;

        return -1;
        
    }
};