class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n=s1.size(),m=s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return f(n,m,s1,s2,dp);
    }

    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(!i || !j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j] =  f(i-1,j-1,s1,s2,dp)+1;
        }

        else
        {
            int c1=f(i-1,j,s1,s2,dp);
            int c2=f(i,j-1,s1,s2,dp);

            return dp[i][j] = max(c1,c2);
        }
    }

};