class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                // finded the break point 
                idx=i;
                break;
            }
        }

        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // now we have to find the smallest number greater nums[i] from i+1 n-1
        for(int i=n-1;i>idx;i--)
        {
            if(nums[i]>nums[idx])
            {
                swap(nums[i],nums[idx]);
                break;
            }
        }

        // now we have to manage the rest of the part 
        reverse(nums.begin()+idx+1,nums.end());
    }
};