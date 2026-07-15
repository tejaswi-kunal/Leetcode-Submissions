class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return f(1,n-2,nums,dp);
    }

    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // we have choice that we can burst baloons from i--->j
        int coins=0,maxi=-1;
        for(int k=i;k<=j;k++)
        {
            coins=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(coins,maxi);
        }

        return dp[i][j] = maxi;
    }
};