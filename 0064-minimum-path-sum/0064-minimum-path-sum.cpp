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

        // now decalre what your function does ->this function will return me the path with min sum (i,j)-->(0,0)
        return func(n-1,m-1,grid,dp);
        
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