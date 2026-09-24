class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0,j=1;
        int count=1;
        while(j<nums.size())
        {
            if(nums[i]==nums[j] && count==1)
            {
                i++;
                swap(nums[i],nums[j]);
                count=2;
            }

            else if(nums[i]!=nums[j])
            {
                i++;
                swap(nums[i],nums[j]);
                count=1;
            }

            j++;
        }

        return i+1;
        
    }
};