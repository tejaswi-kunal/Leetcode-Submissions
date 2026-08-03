class Solution {
public:
    bool predictTheWinner(vector<int>& nums) 
    {
        // now instead of calculating best score of player1 ,we can directly calculate the diffrence of ply1-ply2
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        vector<vector<bool>>visited(n,vector<bool>(n,0));

        if(solve(0,n-1,nums,dp,visited)>=0)
        {
            return 1;
        }

        return 0;
    
    }

    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp,vector<vector<bool>>&visited)
    {
        if(i>j)
        {
            return 0;
        }

        if(visited[i][j])
        {
            return dp[i][j];
        }

        // now we have two choices each time for each player
        int c1=0,c2=0;

        c1=nums[i]-solve(i+1,j,nums,dp,visited);
        c2=nums[j]-solve(i,j-1,nums,dp,visited);

        visited[i][j]=1;

        return dp[i][j] = max(c1,c2);
    }
};