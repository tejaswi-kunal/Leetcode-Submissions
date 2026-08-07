class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>dp(n+1,0);

        for(int i=1;i<=n;i++)
        {
            int j=1;
            int mini=1e8;
            while(j*j<=i)
            {
                mini=min(mini,dp[i-j*j]+1);
                j++;
            }

            dp[i]=mini;
        }

        return dp[n];
        
    }
};