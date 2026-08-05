class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) 
    {
        // first we have to form the adj list 
        vector<vector<int>>adj(n);

        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }

        // now we have to perform the first bfs from the method with bug
        vector<int>visited(n,0);

        queue<int>q;
        q.push(k);
        visited[k]=1;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            // now we have to visit all its neighbours which are part of suspicious methods 
            for(auto &it : adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }

        // now we have to visit other nodes 
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=2;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    // now we have to all its neighbours and check if any of them are not part of suspicous nodes 
                    for(auto &it : adj[node])
                    {
                        if(visited[it]==1)
                        {
                            flag=true;
                            break;
                        }

                        else if(visited[it]==0)
                        {
                            visited[it]=2;
                            q.push(it);
                        }
                    }
                }
            }
        }

        vector<int>ans;
        if(flag==true)
        {
            for(int i=0;i<n;i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        else
        {
            for(int i=0;i<n;i++)
            {
                if(visited[i]!=1)
                {
                    ans.push_back(i);
                }
            }

            return ans;
        }

    }
};