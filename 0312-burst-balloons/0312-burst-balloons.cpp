class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));


        // now we have to covert this into tabulation
        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<=n-2;j++)
            {
                int cost=0,maxi=-1;

                for(int k=i;k<=j;k++)
                {
                    // we will be choosing the kth baloon which we will burst at last 
                    cost=(nums[i-1]*nums[k]*nums[j+1])+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,cost);
                }

                dp[i][j]=maxi;
            }
        }

        return dp[1][n-2];
        
    }

    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // we have choice that we can burst baloons from i--->j
        int coins=0,maxi=-1;
        for(int k=i;k<=j;k++)
        {
            coins=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(coins,maxi);
        }

        return dp[i][j] = maxi;
    }
};