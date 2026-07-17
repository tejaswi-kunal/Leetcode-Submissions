class Solution {
public:
    int n,m;

    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        n=mat.size(),m=mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,1e9));
        
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        int dist=0;
        while(!q.empty())
        {
            dist++;
            int s=q.size();
            for(int t=0;t<s;t++)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();

                // now we have to visit all its neighbours 
                for(int k=0;k<4;k++)
                {
                    if(valid(i+row[k],j+col[k]) && mat[i+row[k]][j+col[k]] && ans[i+row[k]][j+col[k]]>dist)
                    {
                        ans[i+row[k]][j+col[k]]=dist;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            }
        }

        return ans;
    }

};