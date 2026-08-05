class Solution {
public:
    int minDifficulty(vector<int>& diff, int d) 
    {
        int n=diff.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));

        // solve(i,d)->this function will return the min diff of job schedule from i--n-1the task and d days
        int result=solve(0,d,diff,dp);

        if(result==1e8)
        {
            return -1;
        }
        return result;
    }

    int solve(int i,int d,vector<int>&diff,vector<vector<int>>&dp)
    {
        int n=diff.size();
        if(d==1 && i<n)
        {
            // we have to perform all the remaining tasks
            int maxi=-1e8;
            for(int j=i;j<n;j++)
            {
                maxi=max(maxi,diff[j]);
            }
            return maxi;
        }

        else if(d>0 && i>=n)
        {
            return 1e8;
        }

        // now we have to memoize the result
        if(dp[i][d]!=-1)
        {
            return dp[i][d];
        }

        // now we have certian choices for each index 
        int maxi=-1e8,c=1e8;
        for(int j=i;j<diff.size();j++)
        {
            maxi=max(maxi,diff[j]);
            c=min(c,maxi+solve(j+1,d-1,diff,dp));
        }

        return dp[i][d] = c;
    }
};