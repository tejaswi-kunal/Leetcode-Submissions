class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int start, int end) 
    {
        // first we have to build the adj list  
        vector<vector<pair<int,double>>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],p[i]});
            adj[edges[i][1]].push_back({edges[i][0],p[i]});
        }

        vector<double>dist(n,0);
        vector<bool>visited(n);
        priority_queue<pair<double,int>> pq;

        pq.push({1,start});
        dist[start]=1;

        while(!pq.empty())
        {
            int Node=pq.top().second;
            pq.pop();

            if(visited[Node])
            {
                continue;
            }

            visited[Node]=1;

            if(Node==end)
            {
                return dist[Node];
            }

            // now we have to explore this node 
            for(auto [neigh,wt] : adj[Node])
            {
                if(dist[neigh]<dist[Node]*wt)
                {
                    dist[neigh]=dist[Node]*wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }

        return 0;
        
    }
};