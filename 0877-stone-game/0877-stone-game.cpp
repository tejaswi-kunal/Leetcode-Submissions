class Solution {
public:
    bool stoneGame(vector<int>& nums) 
    {
        // lets find the maximum number of piles alice can earn 
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));

        int ply1=solve(0,n-1,0,nums,dp);
        int ply2=accumulate(nums.begin(),nums.end(),0)-ply1;

        if(ply1>ply2)
        {
            return true;
        }

        else
        {
            return false;
        }
        
    }

    int solve(int i,int j,int chance,vector<int>&nums, vector<vector<vector<int>>>&dp)
    {
        if(i>j)
        {
            return 0;
        }

        // now we have to memoize the result
        if(dp[i][j][chance]!=-1)
        {
            return dp[i][j][chance];
        }

        // now each time we have two choices for the player 1
        int take_i=0,take_j=0;
        int result;
        if(chance==0)
        {
            result=-1;
        }

        else
        {
            result=INT_MAX;
        }

        if(chance==0)
        {
            take_i=nums[i]+solve(i+1,j,1,nums,dp);
            take_j=nums[j]+solve(i,j-1,1,nums,dp);
            result=max(take_i,take_j);
        }
        else
        {
            take_i=solve(i+1,j,0,nums,dp);
            take_j=solve(i,j-1,0,nums,dp);
            result=min(take_i,take_j);
        }

        return dp[i][j][chance] = result;
    }
};