class Solution {
public:
    using ll=long long;
    struct state {
        int r, c, p;
        ll cost;
    };

    struct cmp {
        bool operator()(const state& a, const state& b) {
            return a.cost > b.cost;
        }
    };

    ll cost(int i,int j)
    {
        return 1LL*(i+1)*(j+1);
    }

    int rw,cl;

    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j)
    {
        return i>=0&&i<rw&&j>=0&&j<cl;
    }

    priority_queue<state, vector<state>, cmp> pq;
    long long minCost(int n, int m, vector<vector<int>>& penalty) 
    {
        rw=n,cl=m;
        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(2,0)));
        vector<vector<vector<ll>>>dist(n,vector<vector<ll>>(m,vector<ll>(2,LLONG_MAX)));

        pq.push({0,0,1,1});
        dist[0][0][1]=1;

        while(!pq.empty())
        {
            state s=pq.top();
            pq.pop();

            if(visited[s.r][s.c][s.p])
            {
                continue;
            }

            visited[s.r][s.c][s.p]=1;
            int i=s.r,j=s.c,p=s.p;

            if(i==n-1 && j==m-1)
            {
                return dist[i][j][p];
            }


            // now we have to explore all its neighbours 
            for(int k=0;k<4;k++)
            {
                if(valid(i+row[k],j+col[k]))
                {
                    int nr=i+row[k];
                    int nc=j+col[k];
                    // up or left
                    if(k==0 || k==2)
                    {
                        if(p==0 && dist[nr][nc][!p]>dist[i][j][p]+cost(nr,nc))
                        {
                            dist[nr][nc][!p]=dist[i][j][p]+cost(nr,nc);
                            pq.push({nr,nc,!p,dist[nr][nc][!p]});
                        }

                        else if(p==1 && dist[nr][nc][!p] > dist[i][j][p] + cost(nr,nc) + penalty[i][j])
                        {
                            dist[nr][nc][!p] = dist[i][j][p] + cost(nr,nc) + penalty[i][j];
                            pq.push({nr,nc,!p,dist[nr][nc][!p]});
                        }
                    }

                    // down or right
                    else
                    {
                        if(p==1 && dist[nr][nc][!p]>dist[i][j][p]+cost(nr,nc))
                        {
                            dist[nr][nc][!p]=dist[i][j][p]+cost(nr,nc);
                            pq.push({nr,nc,!p,dist[nr][nc][!p]});
                        }

                        else if(p==0 && dist[nr][nc][!p] > dist[i][j][p] + cost(nr,nc) + penalty[i][j])
                        {
                            dist[nr][nc][!p] = dist[i][j][p] + cost(nr,nc) + penalty[i][j];
                            pq.push({nr,nc,!p,dist[nr][nc][!p]});
                        }
                    }
                }
            }

            // if we only want to switch the parity 
            if(dist[i][j][!p] > dist[i][j][p] + penalty[i][j])
            {
                dist[i][j][!p] = dist[i][j][p] + penalty[i][j];
                pq.push({i,j,!p,dist[i][j][!p]});
            }
        }

        return -1;
    }
};