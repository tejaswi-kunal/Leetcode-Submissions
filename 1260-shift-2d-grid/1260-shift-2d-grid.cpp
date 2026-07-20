class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        if(k==0)
        {
            return grid;
        }

        for(int t=0;t<k;t++)
        {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j<m-1)
                {
                    // means in col its not the last index -->n-1
                    ans[i][j+1]=grid[i][j];
                }

                else if(j==m-1 && i!=n-1)
                {
                    ans[i+1][0]=grid[i][j];
                }

                else
                {
                    ans[0][0]=grid[i][j];
                }
            }
        }

        grid=ans;
        }

        return ans;
        
    }
};