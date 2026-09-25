class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        // dp approch 
        int n=nums.size();

        vector<int>dp(n);

        dp[0]=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(dp[i],ans);
        }

        return ans;
        
    }
};