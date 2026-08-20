class Solution {
public:
    int n,m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int countSquares(vector<vector<int>>& mat) 
    {
        n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        // now we have to maintain the tabulation 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                {
                    if(valid(i-1,j) && valid(i,j-1) && valid(i-1,j-1))
                    {
                        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }

                    else
                    {
                        dp[i][j]=1;
                    }
                }

                else
                {
                    dp[i][j]=0;
                }
            }
        }

        // now we have to sum up all the count 
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=dp[i][j];
            }
        }

        return ans;
    }
};