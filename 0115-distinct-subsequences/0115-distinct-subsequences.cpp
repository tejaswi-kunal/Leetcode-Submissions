class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return f(n,m,s,t,dp);
    }

    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(!j)
        {
            return 1;
        }

        else if(!i)
        {
            return 0;
        }

        // now check if this case is already computed
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // lets explore what are choices we have for each index
        if(s[i-1]==t[j-1])
        {
            int c1=f(i-1,j-1,s,t,dp);
            int c2=f(i-1,j,s,t,dp);

            return dp[i][j] = c1+c2;
        }

        else
        {
            return dp[i][j] = f(i-1,j,s,t,dp);
        }
    }
};