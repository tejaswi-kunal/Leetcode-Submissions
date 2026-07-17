class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) 
    {
        // first we have to prepare the adj list 
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);

        for(auto it : prereq)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        // now we have to check using topo sort if we can visit all the nodes
        queue<int>q;
        for(int i=0;i<indeg.size();i++)
        {
            if(!indeg[i])
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int Node = q.front();
            q.pop();

            // now we have to decrease the indeg all of its neighbours and see if any one of them becomes 
            // independent 

            for(auto it : adj[Node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }

        for(auto it : indeg)
        {
            if(it)
            {
                return false;
            }
        }

        return true;
        
    }
};