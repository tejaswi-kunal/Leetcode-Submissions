class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,strs);
    }

    int solve(int i,int m,int n,vector<string>&strs)
    {
        if(i==strs.size())
        {
            return 0;
        }

        if(!n && !m)
        {
            return 0;
        }

        if(dp[i][m][n]!=-1)
        {
            return dp[i][m][n];
        }

        int c1=0,c2=0;

        int currn=0,currm=0;

        for(auto it : strs[i])
        {
            if(it=='0')
            {
                currm++;
            }
            else
            {
                currn++;
            }
        }

        if(currm<=m && currn<=n)
        {
            c1=1+solve(i+1,m-currm,n-currn,strs);
        }

        c2=solve(i+1,m,n,strs);

        return dp[i][m][n] = max(c1,c2);
    }
};