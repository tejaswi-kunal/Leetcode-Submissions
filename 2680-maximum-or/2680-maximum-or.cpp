class Solution {
public:
    using ll = long long;
    long long maximumOr(vector<int>& nums, int k) 
    {
        // first we have to form the prefix and suffix or results 
        int n=nums.size();

        vector<ll>pref(n);
        vector<ll>suff(n);

        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1] | nums[i];
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1] | nums[i];
        }

        ll ans=-1;
        for(int j=0;j<n;j++)
        {
            int i=j-1;
            int l=j+1;

            ll mid=1LL*nums[j]<<k;
            ll left=0,right=0;

            if(i>=0)
            {
                left=pref[i];
            }
            if(l<n)
            {
                right=suff[l];
            }

            ans=max(ans,left | mid | right);
        }

        return ans;   
        
    }
};