class Solution {
public:
    using ll=long long;
    ll dp[100001][2];
    long long maxAlternatingSum(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,nums);
    }

    ll solve(int i,int chance,vector<int>&nums)
    {
        if(i==nums.size())
        {
            return 0;
        }

        if(dp[i][chance]!=-1)
        {
            return dp[i][chance];
        }

        // we have two choices 
        ll c1=0,c2=0;

        if(chance==0)
        {
            c1=-nums[i]+solve(i+1,1,nums);
            c2=solve(i+1,0,nums);
        }

        else
        {
            c1=nums[i]+solve(i+1,0,nums);
            c2=solve(i+1,1,nums);
        }

        return dp[i][chance] = max(c1,c2);
    }
};