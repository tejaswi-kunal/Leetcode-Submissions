class Solution {
public:
    int n,m;
    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    int minCost(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();

        vector<vector<bool>>explored(n,vector<bool>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,1e8));

        deque<tuple<int,int,int>>dq;
        dq.push_front({0,0,0});
        dist[0][0]=0;

        while(!dq.empty())
        {
            auto [cost,row,col]=dq.front();
            dq.pop_front();

            if(explored[row][col])
            {
                continue;
            }

            explored[row][col]=1;

            // now we have to relax the edges 
            for(int k=1;k<=4;k++)
            {
                int nrow=row+r[k-1];
                int ncol=col+c[k-1];

                if(!valid(nrow,ncol))
                {
                    continue;
                }

                int ncost=0;
                if(k!=grid[row][col])
                {
                    ncost=1;
                }

                if(ncost+cost<dist[nrow][ncol])
                {
                    dist[nrow][ncol]=ncost+cost;

                    if(ncost==0)
                    {
                        dq.push_front({cost,nrow,ncol});
                    }

                    else
                    {
                        dq.push_back({ncost+cost,nrow,ncol});
                    }
                }
            }
        }

        return dist[n-1][m-1];
        
    }
};