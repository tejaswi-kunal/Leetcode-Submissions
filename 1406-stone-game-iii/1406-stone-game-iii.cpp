class Solution {
public:
    using ll = long long;
    string stoneGameIII(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n);
        vector<bool>visited(n,0);

        // here since nums[i]<0 for some cases we have to second approch where solve() will return diff
        // scores of ply1 and ply2
        int result=solve(0,nums,dp,visited);

        if(result>0)
        {
            return "Alice";
        }

        else if(result==0)
        {
            return "Tie";
        }

        else 
        {
            return "Bob";
        }
    }

    ll solve(int i,vector<int>&nums,vector<int>&dp,vector<bool>&visited)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(visited[i])
        {
            return dp[i];
        }

        // we have three choices for each player
        ll c1=INT_MIN,c2=INT_MIN,c3=INT_MIN;
        int n=nums.size();

        c1=nums[i]-solve(i+1,nums,dp,visited);

        if(i+1<n)
        {
            c2=nums[i]+nums[i+1]-solve(i+2,nums,dp,visited);
        }

        if(i+2<n)
        {
            c3=nums[i]+nums[i+1]+nums[i+2]-solve(i+3,nums,dp,visited);
        }

        visited[i]=1;
        return dp[i] = max(c1,max(c2,c3));
    }
};