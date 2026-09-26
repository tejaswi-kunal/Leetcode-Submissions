class Solution {
public:
    int dp[30001][2];
    int maxProfit(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp)); 
        return solve(0,0,nums);
    }

    int solve(int i,int j,vector<int>&price)
    {
        if(i==price.size()-1)
        {
            if(j==0)
            {
                return 0;
            }

            else
            {
                return price[i];
            }
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int c1=0,c2=0;
        if(j==0)
        {
            c1=-price[i]+solve(i+1,1,price);

            c2=solve(i+1,0,price);
        }

        else if(j==1)
        {
            c1=price[i]+solve(i+1,0,price);

            c2=solve(i+1,1,price);
        }

        return dp[i][j] = max(c1,c2);
    }
};