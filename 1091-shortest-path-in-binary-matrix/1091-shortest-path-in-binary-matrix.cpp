class Solution {
public:
    int n,m;

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int row[8]={1,-1,0,0,1,-1,1,-1};
    int col[8]={0,0,1,-1,1,1,-1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;

        if(grid[0][0])
        {
            return -1;
        }

        q.push({0,0});
        grid[0][0]=1;

        // now we have to perform the bfs to find the shortest path 
        int dist=0;
        while(!q.empty())
        {
            dist++;
            int s=q.size();
            for(int t=0;t<s;t++)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();

                if(i==n-1 && j==m-1)
                {
                    return dist;
                }
                // now we have to visit all its neighbours
                for(int k=0;k<8;k++)
                {
                    if(valid(i+row[k],j+col[k]) && !grid[i+row[k]][j+col[k]])
                    {
                        grid[i+row[k]][j+col[k]]=1;
                        q.push({i+row[k],j+col[k]});
                    }
                }

            }
        }

        return -1;


    }
};