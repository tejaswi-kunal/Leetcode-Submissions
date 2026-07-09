class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int>dp(n,-1);

        // base case intialization
        dp[0]=nums[0];
        
        if(n>=2)
        {
            dp[1]=max(nums[0],nums[1]);
        }

        for(int i=2;i<n;i++)
        {
            int c1=nums[i]+dp[i-2];
            int c2=dp[i-1];

            dp[i]=max(c1,c2);
        }

        return dp[n-1];
    }
};