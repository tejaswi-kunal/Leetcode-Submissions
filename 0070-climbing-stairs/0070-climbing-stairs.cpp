class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,-1);

        return func(n,dp);
        
    }

    int func(int n,vector<int>&dp)
    {
        if(!n || n==1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        // choices
        int c1=func(n-1,dp);
        int c2=func(n-2,dp);

        // result on the basis of those choices 
        return dp[n]=c1+c2;
    }
};