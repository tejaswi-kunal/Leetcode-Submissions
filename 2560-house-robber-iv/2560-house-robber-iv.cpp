class Solution {
public:
    bool check(int ans,vector<int>&nums,int k)
    {
        // now we have to check if we can select k elements 
        int i=0;
        int count=0;
        while(i<nums.size())
        {
            if(nums[i]<=ans)
            {
                count++;
                i++;
            }
            i++;
        }

        if(count>=k)
        {
            return 1;
        }
        return 0;
    }

    int minCapability(vector<int>& nums, int k) 
    {
        // first we have to find the max capiblity using the bs 
        int start=0,end=*max_element(nums.begin(),nums.end());
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

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