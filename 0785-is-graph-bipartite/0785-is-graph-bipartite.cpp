class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        // a graph will be bipartite if we can divide all the nodes in two sets such that no adj nodes are in same set 
        vector<int>visited(graph.size(),-1);

        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==-1)
            {
                visited[i]=1;
                if(!check(i,graph,visited))
                {
                    return 0;
                }
            }
        }

        return 1;

        
    }

    bool check(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        for(auto it : adj[node])
        {
            if(visited[it]!=-1 && visited[it]==visited[node])
            {
                return 0;
            }

            else if(visited[it]==-1)
            {
                visited[it]=!visited[node];
                if(!check(it,adj,visited))
                {
                    return 0;
                }
            }
            
        }

        return 1;
    }
};