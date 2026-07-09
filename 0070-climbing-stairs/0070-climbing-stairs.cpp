class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,-1);
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            int c1=dp[i-1];
            int c2=dp[i-2];

            dp[i]=c1+c2;
        }

        return dp[n];
        
    }
};