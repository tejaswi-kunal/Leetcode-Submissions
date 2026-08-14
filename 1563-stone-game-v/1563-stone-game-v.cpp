class Solution {
public:
    int stoneGameV(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,nums,dp);
    }

    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // this function will return the max score alice can get i---j
        int left=0;
        int total=0;
        int ans=0;
        for(int k=i;k<=j;k++)
        {
            total+=nums[k];
        }

        for(int k=i;k<j;k++)
        {
            left+=nums[k];
            int right=total-left;

            // now for this partition its the choice of bob 
            if(left<right)
            {
                // then the left part will be choosen 
                ans=max(ans,left+solve(i,k,nums,dp));
            }

            else if(left > right)
            {
                // then the right part will be choosen 
                ans=max(ans,right+solve(k+1,j,nums,dp));
            }

            else
            {
                // its the choice of alice which part she want choose 
                // she will choose the part with max score
                ans=max(ans,left+max(solve(i,k,nums,dp),solve(k+1,j,nums,dp)));
            }
        }

        return dp[i][j] = ans;
    }
};