class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) 
    {
        // now here we just have to return the actual topo sort 
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);

        for(auto it : prereq)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        // now we have to perform the topo sort 
        queue<int>q;
        for(int i=0;i<indeg.size();i++)
        {
            if(!indeg[i])
            {
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty())
        {
            int Node = q.front();
            q.pop();

            ans.push_back(Node);

            // now we have to visit all its neighbours
            for(auto it : adj[Node])
            {
                indeg[it]--;

                if(!indeg[it])
                {
                    q.push(it);
                }
            }
        }

        // now we have to check if have visited all the nodes
        for(auto it : indeg)
        {
            if(it)
            {
                vector<int>a;
                return a;
            }
        }
        

        return ans;
    }
};