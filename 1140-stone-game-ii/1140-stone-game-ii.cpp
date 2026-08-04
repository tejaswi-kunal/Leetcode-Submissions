class Solution {
public:
    int stoneGameII(vector<int>& nums) 
    {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(2*n));
        vector<vector<bool>>visited(n,vector<bool>(2*n,0));

        int diff=solve(0,1,nums,dp,visited);
        int sum=accumulate(nums.begin(),nums.end(),0);

        return (diff+sum)/2;
        
    }

    int solve(int i,int m,vector<int>&nums,vector<vector<int>>&dp,vector<vector<bool>>&visited)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(visited[i][m])
        {
            return dp[i][m];
        }

        int result=INT_MIN,s=0;
        int n=nums.size();

        for(int j=1;j<=2*m;j++)
        {
            if(i+j-1<n)
            {
                s+=nums[i+j-1];
                result=max(result,s-solve(i+j,max(m,j),nums,dp,visited));
            }
        }

        visited[i][m]=1;
        return dp[i][m] = result;
    }
};