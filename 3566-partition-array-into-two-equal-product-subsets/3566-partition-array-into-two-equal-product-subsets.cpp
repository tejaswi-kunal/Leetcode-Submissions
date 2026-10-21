class Solution {
public:
    using ll=long long;
    bool checkEqualPartitions(vector<int>& nums, long long target)
    {        

        return solve(1,1,0,target,nums);
    }

    bool solve(ll curr1,ll curr2,int i,ll target,vector<int>&nums)
    {
        if(i==nums.size())
        {
            if(curr1==target  && curr2==target)
            {
                return 1;
            }

            return 0;
        }

        // in curr1
        if(curr1<=target/nums[i])
        {
            if(solve(curr1*nums[i],curr2,i+1,target,nums))
            {
                return 1;
            }
        }

        if(curr2<=target/nums[i])
        {
            return solve(curr1,curr2*nums[i],i+1,target,nums);
        }

        return 0;
    }
};