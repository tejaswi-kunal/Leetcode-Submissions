class Solution {
public:
    int solve(int nums)
    {
        int sum=0;
        while(nums)
        {
            int rem=nums%10;
            nums/=10;

            sum+=rem;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(i==solve(nums[i]))
            {
                return i;
            }
        }

        return -1;
        
    }
};