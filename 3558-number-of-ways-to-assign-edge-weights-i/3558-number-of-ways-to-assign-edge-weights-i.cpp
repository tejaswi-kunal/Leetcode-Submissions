class Solution {
public:
    using ll=long long;
    int mod=1e9+7;
    int pow(ll base,ll exp)
    {
        ll ans=1;

        while(exp)
        {
            if(exp & 1)
            {
                ans=((ans%mod)*(base%mod))%mod;
            }

            base=((base%mod)*(base%mod))%mod;
            exp>>=1;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        // first we have to build the adj list
        int n=edges.size();
        vector<vector<int>>adj(n+2);

        for(auto &it : edges)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // now we we have to find the depth of the tree
        vector<int>visited(n+2,0);
        
        queue<int>q;
        q.push(1);
        visited[1]=1;
        int depth=0;
        while(!q.empty())
        {
            int t=q.size();
            while(t--)
            {
                int node = q.front();
                q.pop();
                for(auto it : adj[node])
                {
                    if(!visited[it])
                    {
                        visited[it]=1;
                        q.push(it);
                    }
                }
            }

            depth++;
        }

        depth--;
        // now we have to find total number of permutations 
        return pow(2,depth-1);
    }
};