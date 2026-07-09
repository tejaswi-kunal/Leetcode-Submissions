class Solution {
public:
    int row,col;

    bool valid(int i,int j)
    {
        return i>=0&&i<row&&j>=0&&j<col;
    }

    int uniquePaths(int n, int m) 
    {
        row=n,col=m;

        vector<vector<int>>dp(n,vector<int>(m,-1));

        // now we have to declare this function->this function will return the number of ways we can go from 
        // index i,j--->0,0

        return func(n-1,m-1,dp);
        
    }

    int func(int i,int j,vector<vector<int>>&dp)
    {
        if(!i && !j)
        {
            return 1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int c1=0,c2=0;
        if(valid(i-1,j))
        {
            c1=func(i-1,j,dp);
        }

        if(valid(i,j-1))
        {
            c2=func(i,j-1,dp);
        }

        return  dp[i][j] = c1+c2;
    }
};