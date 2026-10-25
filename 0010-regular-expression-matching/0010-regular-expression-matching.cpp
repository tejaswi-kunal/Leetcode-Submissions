class Solution {
public:
    int dp[25][25];    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));

        return solve(0,0,s,p);
    }

    bool solve(int i,int j,string &s,string &p)
    {
        if(i==s.size() && j==p.size())
        {
            return 1;
        }

        else if(i>s.size() || j>p.size())
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(j+1<p.size() && p[j+1]=='*')
        {
            if(p[j]=='.' || s[i]==p[j])
            {
                return dp[i][j]=solve(i+1,j,s,p) || solve(i,j+2,s,p);
            }

            else
            {
                return dp[i][j]=solve(i,j+2,s,p);
            }
        }

        else if(p[j]=='.' || s[i]==p[j])
        {
            return dp[i][j] = solve(i+1,j+1,s,p);
        }

        return dp[i][j] = 0;
    }
};