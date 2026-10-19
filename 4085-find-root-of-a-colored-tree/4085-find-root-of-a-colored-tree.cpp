class Solution {
public:

    pair<int,int>directedEdge(int u,int v,string &colors)
    {
        if((colors[u]=='R' && colors[v]=='B') || (colors[u]=='B' && colors[v]=='W') || (colors[u]=='W' && colors[v]=='R'))
        {
            return {u,v};
        }

        else if((colors[v]=='R' && colors[u]=='B') || (colors[v]=='B' && colors[u]=='W') || (colors[v]=='W' && colors[u]=='R'))
        {
            return {v,u};
        }

        return {-1,-1};
    }

    int findColoredRoot(vector<vector<int>>& edges, string colors) 
    {
        // first we have to form the indegree and the outdegree array
        int n=edges.size()+1;
        vector<int>indeg(n,0);
        vector<int>outdeg(n,0);

        for(auto &it: edges)
        {
            auto [u,v]=directedEdge(it[0],it[1],colors);

            if(u==-1 && v==-1)
            {
                return -1;
            }

            outdeg[u]++;
            indeg[v]++;
        }

        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(outdeg[i]>2 || indeg[i]>1)
            {
                return -1;
            }

            if(indeg[i]==0 && outdeg[i]>0)
            {
                ans=i;
            }
        }
        
        return ans;
    }
};