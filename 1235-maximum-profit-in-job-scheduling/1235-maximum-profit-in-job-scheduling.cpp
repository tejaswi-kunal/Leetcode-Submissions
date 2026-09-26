class Solution {
public:
    int dp[50001];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        memset(dp,-1,sizeof(dp));

        int n=startTime.size();
        vector<tuple<int,int,int>>nums(n);

        // form the nums array 
        for(int i=0;i<n;i++)
        {
            nums[i]={startTime[i],endTime[i],profit[i]};
        }

        // sort according to start time
        sort(nums.begin(),nums.end());

        return solve(0,nums);
    }

    int BS(int start,int end,int target,vector<tuple<int,int,int>>&nums)
    {
        // first the first idx whose startTime > target
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(get<0>(nums[mid])>=target)
            {
                ans=mid;
                end=mid-1;
            }

            else
            {
                start=mid+1;
            }
        }

        return ans;
    }

    int solve(int i,vector<tuple<int,int,int>>&nums)
    {
        auto &[s,e,p]=nums[i];

        if(i==nums.size()-1)
        {
            return p;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        // we have two choice 
        //not do this job
        int c1=solve(i+1,nums);

        // do this job
        int idx=BS(i+1,nums.size()-1,e,nums);

        int c2=p;
        if(idx!=-1)
        {
            c2+=solve(idx,nums);
        }

        return dp[i] = max(c1,c2);
    }
};