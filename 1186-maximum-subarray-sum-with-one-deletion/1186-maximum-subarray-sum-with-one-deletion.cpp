class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        vector<int>pref(n);
        vector<int>suff(n);

        int ans=nums[0];
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=max(pref[i-1]+nums[i],nums[i]);
            ans=max(ans,pref[i]);
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=max(suff[i+1]+nums[i],nums[i]);
        }

        for(int j=0;j<n;j++)
        {
            int i=j-1,k=j+1;

            // we have option to delete index j
            int s1=0,s2=0;
            if(i>=0)
            {
                s1=pref[i];
            }
            if(k<n)
            {
                s2=suff[k];
            }

            ans=max(ans,s1+s2);
        }

        return ans;
        
    }
};