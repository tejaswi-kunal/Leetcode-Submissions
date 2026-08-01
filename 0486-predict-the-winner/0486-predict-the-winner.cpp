class Solution {
public:
    bool predictTheWinner(vector<int>& nums) 
    {
        // first rec approch --> rec wrt to p1 --->in this player1 will want to maximize his score and p2 will try to 
        // minimize the score of p1 
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int player1=solve(0,n-1,dp,nums);

        int player2=accumulate(nums.begin(),nums.end(),0)-player1;

        if(player1>=player2)
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

        if(i==j)
        {
            return nums[i];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // now we have two choices for p1
        int c1=0,c2=0;

        c1=nums[i]+min(solve(i+2,j,dp,nums),solve(i+1,j-1,dp,nums));
        c2=nums[j]+min(solve(i+1,j-1,dp,nums),solve(i,j-2,dp,nums));

        return dp[i][j] = max(c1,c2);
    }
};