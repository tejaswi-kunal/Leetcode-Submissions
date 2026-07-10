class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;

        for(auto it : nums)
        {
            sum+=it;
        }

        if(sum%2!=0)
        {
            return 0;
        }

        // now we have to find if can achive sum/2 as target using the elements as subset in the arr
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));

        // first we have to define the base case 
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }

        if(nums[0]<=target)
        {
            dp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                // for each index we have two choices 
                bool notTaken=dp[i-1][j];

                bool taken=0;
                if(j-nums[i]>=0)
                {
                    taken=dp[i-1][j-nums[i]];
                }

                dp[i][j]=notTaken || taken;
            }
        }

        return dp[n-1][target];
    }
};