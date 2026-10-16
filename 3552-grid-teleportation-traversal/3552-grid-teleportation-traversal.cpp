class Solution {
public:
    int n,m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    int minMoves(vector<string>& grid) 
    {
        n=grid.size(),m=grid[0].size();

        // now we have to mark all the portals   
        unordered_map<char,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='.' && grid[i][j]!='#')
                {
                    mp[grid[i][j]].push_back({i,j});
                }
            }
        }

        unordered_set<char>used;

        if(grid[n-1][m-1]=='#')
        {
            return -1;
        }

        deque<tuple<int,int,int>>dq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dq.push_front({0,0,0});
        dist[0][0]=0;

        while(!dq.empty())
        {
            auto [cost,r,c]=dq.front();
            dq.pop_front();

            // check if its a stale path 
            if(cost>dist[r][c])
            {
                continue;
            }

            // now we have to visit all its neighbours 
            // using the portal
            if(grid[r][c]!='.' && used.find(grid[r][c])==used.end())
            {
                for(auto [i,j] : mp[grid[r][c]])
                {
                    if(cost<dist[i][j])
                    {
                        dist[i][j]=cost;
                        dq.push_front({cost,i,j});
                    }
                }

                used.insert(grid[r][c]);
            }

            // using the edges 
            for(int k=0;k<4;k++)
            {
                int nr=r+row[k];
                int nc=c+col[k];

                if(!valid(nr,nc) || grid[nr][nc]=='#')
                {
                    continue;
                }

                if(cost+1<dist[nr][nc])
                {
                    dist[nr][nc]=cost+1;
                    dq.push_back({cost+1,nr,nc});
                }
            }
        }

        if(dist[n-1][m-1]!=1e9)
        return dist[n-1][m-1];
        
        return -1;
    }
};