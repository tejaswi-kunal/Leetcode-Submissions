class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int v=isConnected.size();
        vector<int>visited(v,0);
        int ans=0;
        // we just have to return the number of componenets 
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                bfs(i,visited,isConnected);
                ans++;
            }
        }

        return ans;
        
    }

    void bfs(int node,vector<int>&visited,vector<vector<int>>&adj)
    {
        visited[node]=1;
        queue<int>q;
        q.push(node);

        while(!q.empty())
        {
            int Node=q.front();
            q.pop();

            // now we have to visit its neighbours
            for(int i=0;i<adj.size();i++)
            {
                if(i==Node)
                {
                    continue;
                }

                else if(adj[Node][i]==1 && !visited[i])
                {
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
};