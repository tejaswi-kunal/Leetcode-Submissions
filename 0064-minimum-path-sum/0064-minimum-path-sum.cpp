class Solution {
public:

    int n,m;

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        // for tabulation first we have to declare the base case 
        dp[0][0]=grid[0][0];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!i && !j)
                {
                    continue;
                }

                int c1=1e8,c2=1e8;
                if(valid(i-1,j))
                {
                    c1=dp[i-1][j];
                }

                if(valid(i,j-1))
                {
                    c2=dp[i][j-1];
                }

                dp[i][j]=min(c1,c2)+grid[i][j];
            }
        }

        return dp[n-1][m-1];
        
    }

    int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(!i && !j)
        {
            return grid[0][0];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int c1=1e8,c2=1e8;

        if(valid(i-1,j))
        {
            c1=func(i-1,j,grid,dp);
        }

        if(valid(i,j-1))
        {
            c2=func(i,j-1,grid,dp);
        }

        return dp[i][j]= min(c1,c2)+grid[i][j];
    }
};