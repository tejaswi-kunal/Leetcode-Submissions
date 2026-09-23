class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) 
    {
        // first we have to build the adj list 
        k++;
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : f)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<vector<int>>dist(n,vector<int>(k+1,1e8));
        vector<vector<bool>>explored(n,vector<bool>(k+1,0));

        
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> >pq;

        pq.push({0,{src,k}});
        dist[src][k]=0;
        while(!pq.empty())
        {
            int node=pq.top().second.first;
            int stops=pq.top().second.second;

            pq.pop();

            if(explored[node][stops])
            {
                continue;
            }

            explored[node][stops]=1;

            if(stops==0)
            {
                continue;
            }

            // now we have to explore all its neighbours
            for(auto &[neigh,wt] : adj[node])
            {
                if(dist[neigh][stops-1]>dist[node][stops]+wt)
                {
                    dist[neigh][stops-1]=dist[node][stops]+wt;
                    pq.push({dist[neigh][stops-1],{neigh,stops-1}});
                }
            }
        }

        int ans=1e8;
        for(int i=0;i<=k;i++)
        {
            ans=min(ans,dist[dst][i]);
        }

        if(ans==1e8)
        {
            return -1;
        }

        return ans;

    }
};