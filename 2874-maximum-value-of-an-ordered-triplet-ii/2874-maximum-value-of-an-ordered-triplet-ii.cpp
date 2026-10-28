class Solution {
public:
    using ll = long long;
    long long maximumTripletValue(vector<int>& nums) 
    {
        // first we have to form the prefix and the suffix 
        vector<int>pref(nums.size());
        vector<int>suff(nums.size());

        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pref[i]=max(nums[i],pref[i-1]);
        }

        suff[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            suff[i]=max(nums[i],suff[i+1]);
        }

        // now we will form the triplets with index j in the middle 
        ll ans=0;
        for(int j=1;j<nums.size()-1;j++)
        {
            int i=j-1;
            int k=j+1;

            ll sum=1LL*(pref[i]-nums[j])*suff[k];

            if(sum>0)
            {
                ans=max(ans,sum);
            }
        }

        return ans;
        
    }
};