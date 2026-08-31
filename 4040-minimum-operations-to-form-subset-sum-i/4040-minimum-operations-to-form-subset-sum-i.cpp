class Solution {
public:
    int dp[101][5005];
    int minOperations(vector<int>& nums, int sum) 
    {
        memset(dp,-1,sizeof(dp));

        int ans = solve(nums.size()-1,sum,nums);

        if(ans<1e8)
        {
            return ans;
        }

        return -1;
    }

    int solve(int i,int sum,vector<int>&nums)
    {
        if(!sum)
        {
            return 0;
        }

        if(i<0)
        {
            return 1e8;
        }

        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }

        int c2=1e8,c3=1e8,c4=1e8;
        int curr=nums[i];

        // 2-->take the multiple of nums[i]
        int count=0;
        while(curr<=sum)
        {
            c2=min(c2,solve(i-1,sum-curr,nums)+count);
            count++;
            curr*=2;
        }

        count=1;
        curr=nums[i]/2;
        while(curr>0)
        {
            if(sum-curr>=0)
            c3=min(c3,solve(i-1,sum-curr,nums)+count);
            
            count++;
            curr/=2;
        }

        c4=solve(i-1,sum,nums);

        return dp[i][sum] = min({c2,c3,c4});
    }
};