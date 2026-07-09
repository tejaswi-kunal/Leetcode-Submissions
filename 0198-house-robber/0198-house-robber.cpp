class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int>dp(n,-1);

        return func(n-1,nums,dp);
        
    }

    int func(int i,vector<int>&nums,vector<int>&dp)
    {
        if(!i)
        {
            return nums[0];
        }

        else if(i==1)
        {
            return max(nums[1],nums[0]);
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int c1=nums[i]+func(i-2,nums,dp);
        int c2=func(i-1,nums,dp);

        return dp[i]=max(c1,c2);
    }
};