class Solution {
public:
    int stoneGameVIII(vector<int>& stones) 
    {
        int n=stones.size();
        vector<int>dp(n);
        vector<bool>mp(n,0);
        vector<int>prefix(n,0);

        prefix[0]=stones[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+stones[i];
        }

        return solve(1,prefix,dp,mp);    
    }

    int solve(int i,vector<int>&prefix,vector<int>&dp,vector<bool>&mp)
    {
        // base caee is when only element is remaining 
        if(i==prefix.size()-1)
        {
            return prefix[i];
        }

        if(mp[i]!=0)
        {
            return dp[i];
        }

        // now we have to explore what choices each player have 
        // each time a player will have option if he/she want to go till this option or more further
        // take
        int take=prefix[i]-solve(i+1,prefix,dp,mp);

        int skip=solve(i+1,prefix,dp,mp);

        mp[i]=1;
        return dp[i]=max(take,skip);
    }
};