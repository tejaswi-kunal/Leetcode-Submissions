class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) 
    {
        int n=nums.size();
        vector<int>pref(n,1);
        vector<int>suff(n,1);
        
        vector<int>ans;
        if(time==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                pref[i]=pref[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            {
                suff[i]=suff[i+1]+1;
            }
        }

        // now we have to find the good indexes 
        
        for(int j=time;j<n-time;j++)
        {
            int i=j-1;
            int k=j+1;

            if((i<0 || (pref[i]>=time && nums[i]>=nums[j])) && (k>=n || (suff[k]>=time && nums[k]>=nums[j])))
            {
                ans.push_back(j);
            }
        }

        return ans;
    }
};