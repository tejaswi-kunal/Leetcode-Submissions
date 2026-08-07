class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>dp(n+1,-1);

        return solve(n,dp);   
    }

    int solve(int n,vector<int>&dp)
    {
        if(!n)
        {
            return 0;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        // so each time we have certain number of options 
        int i=1;
        int mini=1e8;
        while(i*i<=n)
        {
            mini=min(mini,solve(n-i*i,dp)+1);
            i++;
        }

        return dp[n] =  mini;
    }
};