class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);

        

        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),0));
        int c=cuts.size();

        // now lets try the tabulation
        for(int i=c-2;i>=1;i--)
        {
            for(int j=i;j<=c-2;j++)
            {
                int cost=0,mini=INT_MAX;

                for(int k=i;k<=j;k++)
                {
                    cost=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                    mini=min(cost,mini);
                }

                dp[i][j]=mini;
            }
        }

        return dp[1][c-2];

        // this function will return what is the minimum cost to apply the cuts from index 1---->cuts.size()-2
        // return f(1,cuts.size()-2,cuts,dp);
    }

    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {

        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // first we have to explore all the choices for the current subproblem
        int cost=0,mini=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            cost=(cuts[j+1]-cuts[i-1])+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }

        return dp[i][j] = mini;
    }
};