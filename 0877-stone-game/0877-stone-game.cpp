class Solution {
public:
    bool stoneGame(vector<int>& nums) 
    {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        int score1=solve(0,n-1,dp,nums);
        int score2=accumulate(nums.begin(),nums.end(),0)-score1;

        if(score1>score2)
        {
            return 1;
        }

        return 0;
    }

    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // we have two options for player1 
        int c1=0,c2=0;

        c1=nums[i]+min(solve(i+2,j,dp,nums),solve(i+1,j-1,dp,nums));
        c2=nums[j]+min(solve(i+1,j-1,dp,nums),solve(i,j-2,dp,nums));

        return dp[i][j] =  max(c1,c2);
    }
};