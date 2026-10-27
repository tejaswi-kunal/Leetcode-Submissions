class Solution {
public:

    bool check(int mid,vector<int>&nums,int p)
    {
        // now check if we able to have p pairs with mid as max abs diff bw pairs 
        int count = 0;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                count++;
                i+=2;
            }

            else
            {
                i++;
            }
        }

        if(count>=p)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(),nums.end());

        int start=0,end=nums[nums.size()-1]-nums[0];
        int ans=end;

        while(start<=end)
        {
            // selecting max abs diff
            int mid=start+(end-start)/2;

            if(check(mid,nums,p))
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