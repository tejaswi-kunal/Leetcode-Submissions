class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }

    int f(int i,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(!amount)
        {
            return 1;
        }

        if(!i)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }

            return 0;
        }

        // now we have to check if its already computed we will simply return that 
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }

        // we have two choices for each coin
        int notPick=f(i-1,amount,coins,dp);

        int pick=0;
        if(amount-coins[i]>=0)
        {
            pick=f(i,amount-coins[i],coins,dp);
        }

        return dp[i][amount] = pick+notPick;
    }
};