class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>pref(n);
        vector<int>suff(n);

        // first we have to form the prefix and the suffix
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=min(pref[i-1],nums[i]);
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=min(suff[i+1],nums[i]);
        }

        // now we have to caculate the optimal triplets for each index j
        int ans=1e9;
        for(int j=1;j<n-1;j++)
        {
            int i=j-1;
            int k=j+1;

            if(pref[i]<nums[j] && suff[k]<nums[j])
            {
                ans=min(ans,pref[i]+nums[j]+suff[k]);
            }
        }

        if(ans!=1e9)
        return ans;

        return -1;
    }
};