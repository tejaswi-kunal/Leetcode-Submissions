class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) 
    {
        // so we have to return the max sum possible of the subarrays of the array 
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp,k);   
    }

    int solve(int i,vector<int>&nums,vector<int>&dp,int k)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int len=0,maxi1=-1,maxi2=-1;
        int j=i;

        while(j<nums.size() && len<k)
        {
            maxi1=max(maxi1,nums[j]);
            len++;
            j++;

            maxi2=max(maxi2,len*maxi1+solve(j,nums,dp,k));
        }

        return dp[i]=maxi2;
    }
};
