class Solution {
public:
    int n,m;

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    int minimumObstacles(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        

        // now we have to apply the dijkstra algo
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        vector<vector<bool>>exp(n,vector<bool>(m,0));

        
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        while(!pq.empty())
        {
            int r=pq.top().second.first;
            int c=pq.top().second.second;

            pq.pop();

            if(exp[r][c])
            {
                continue;
            }

            exp[r][c]=1;

            // now we have to explore all its neighbours
            for(int k=0;k<4;k++)
            {
                int nr=r+row[k];
                int nc=c+col[k];
                int cost=dist[r][c];

                if(valid(nr,nc))
                {    
                    if(grid[nr][nc]==1)
                    {
                        cost++;
                    }

                    if(cost<dist[nr][nc])
                    {
                        dist[nr][nc]=cost;
                        pq.push({cost,{nr,nc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};