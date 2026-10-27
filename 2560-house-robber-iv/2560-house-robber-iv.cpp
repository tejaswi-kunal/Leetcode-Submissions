class Solution {
public:
    bool check(int mid,vector<int>&nums,int k)
    {
        int prev=-2;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid && i-1!=prev)
            {
                count++;
                prev=i;
            }
        }

        if(count>=k)
        {
            return 1;
        }

        return 0;
        
    }

    int minCapability(vector<int>& nums, int k) 
    {
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        int ans=end;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            // now we have to check if we are able to steal atleast k hoses with max allowed capablity as k
            if(check(mid,nums,k))
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
};