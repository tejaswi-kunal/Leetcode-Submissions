class Solution {
public:
    int n,m;

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    // all possible moves
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};

    int orangesRotting(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();

        // first we have to find all the rotten fruits as the starting source
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        

        int time=0;
        while(!q.empty())
        {
            time++;
            int size=q.size();
            for(int l=0;l<size;l++)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();

                // now we have to visit all its neighbours
                for(int k=0;k<4;k++)
                {
                    if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]==1)
                    {
                        q.push({i+row[k],j+col[k]});
                        grid[i+row[k]][j+col[k]]=2;
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        if(time)
        return time-1;

        return 0;
    }
};