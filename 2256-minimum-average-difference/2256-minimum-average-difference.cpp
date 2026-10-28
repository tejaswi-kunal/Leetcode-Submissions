class Solution {
public:
    using ll=long long;
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int>pref(n);
        vector<int>suff(n);

        ll s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            pref[i]=s/(i+1);
        }

        s=0;
        for(int i=n-1;i>=0;i--)
        {
            s+=nums[i];
            suff[i]=s/(n-i);
        }

        // now we have to find the good index 
        int ans=-1;
        int diff=1e9;
        for(int i=0;i<n;i++)
        {
            int d;
            if(i+1<n)
            {
                d=abs(pref[i]-suff[i+1]);
                
            }
            else
            {
                d=pref[i];
            }

            if(d<diff)
            {
                diff=d;
                ans=i;
            }
        }

        return ans;
        
    }
};