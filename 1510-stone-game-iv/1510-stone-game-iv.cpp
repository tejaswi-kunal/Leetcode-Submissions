class Solution {
public:
    bool winnerSquareGame(int n) 
    {
        // lets build the function which wil return if the player 1 win if both plays optimally 
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return solve(n,0,dp);
        
    }

    int solve(int i,int k,vector<vector<int>>&dp)
    {
        if(!i && k==0)
        {
            return 0;
        }

        else if(!i && k==1)
        {
            return 1;
        }

        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }

        bool canWin;

        if(k==0)
        {
            canWin=0;
        }

        else
        {
            canWin=1;
        }
        // player 1 chance
        if(k==0)
        {
            for(int j=1;j*j<=i;j++)
            {
                canWin=canWin || solve(i-j*j,1,dp);
            }
        }

        // player2 chance 
        else 
        {
            for(int j=1;j*j<=i;j++)
            {
                canWin=canWin && solve(i-j*j,0,dp);
            }
        }

        return dp[i][k] = canWin;
    }
};