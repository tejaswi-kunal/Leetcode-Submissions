class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));

        return numberOfCoins(coins,amount,coins.size()-1,dp);
    }

    int numberOfCoins(vector<int>&coins,int amount,int index,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }

        if(index==0)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }

            return 0;
        }

        //now if the ans for this particular subprobem has been already computed simply return it
        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }

        //now we have couple of choices for each index
        int pick=0,notPick=0;

        if(amount-coins[index]>=0)
        {
            pick=numberOfCoins(coins,amount-coins[index],index,dp);
        }

        notPick=numberOfCoins(coins,amount,index-1,dp);

        return  dp[index][amount]=pick+notPick;
    }
};