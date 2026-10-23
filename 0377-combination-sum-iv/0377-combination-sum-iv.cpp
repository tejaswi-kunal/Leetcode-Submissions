class Solution {
public:
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(dp,-1,sizeof(dp));

        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[i]>=0)
            {
                ans+=solve(target-nums[i],nums);
            }
        }

        return ans;
        
    }

    int solve(int j,vector<int>&nums)
    {
        if(!j)
        {
            return 1;
        }

        if(dp[j]!=-1)
        {
            return dp[j];
        }   

        int comb=0;
        for(int i=0;i<nums.size();i++)
        {
            if(j-nums[i]>=0)
            {
                comb+=solve(j-nums[i],nums);
            }
        }

        return dp[j]=comb;
    }
};