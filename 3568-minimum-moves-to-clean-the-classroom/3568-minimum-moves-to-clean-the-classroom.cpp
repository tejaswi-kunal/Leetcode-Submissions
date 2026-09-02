class Solution {
public:
    int n,m;

    struct state{
        int r,c,l;
    };

    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }

    int minMoves(vector<string>& grid, int energy) 
    {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>bitPos(n,vector<int>(m,-1));

        // first we have to find bitPos of all the litters and the start pos
        int si,sj;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='S')
                {
                    si=i;
                    sj=j;
                }

                else if(grid[i][j]=='L')
                {
                    bitPos[i][j]=count;
                    count++;
                }
            }
        }

        int fullMask=(1<<count)-1;

        // now we have tp apply the bfs
        queue<state>q;
        q.push({si,sj,0});
        
        int visited[21][21][1<<10];
        memset(visited,-1,sizeof(visited));

        // we will with how much energy we have reached this particuar cell
        visited[si][sj][0]=energy;

        // and only visit a cell again if this traversal energy is greater than the previous one

        int move=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                state s=q.front();
                q.pop();

                // first we have to check if all the litters have been covered
                if(s.l==fullMask)
                {
                    return move;
                }

                // if the energy has become zero we cant move forward
                if(visited[s.r][s.c][s.l]==0)
                {
                    continue;
                }
                int e=visited[s.r][s.c][s.l];

                // now explore all its neighbours
                e=e-1;
                for(int k=0;k<4;k++)
                {
                    int newR=s.r+row[k];
                    int newC=s.c+col[k];
                    int newE=e;
                    if(valid(newR,newC) && grid[newR][newC]!='X')
                    {
                        int newL=s.l;
                        if(grid[newR][newC]=='R')
                        {
                            newE=energy;
                        }

                        else if(grid[newR][newC]=='L')
                        {
                            // we have to set the bitPos of the cell
                            int pos=bitPos[newR][newC];
                            newL=s.l|(1<<pos);
                        }

                        if(visited[newR][newC][newL]<newE)
                        {
                            q.push({newR,newC,newL});
                            visited[newR][newC][newL]=newE;
                        }
                    }
                }
            }
            move++;
        }

        return -1;
    }
};