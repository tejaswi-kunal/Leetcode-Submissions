class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        // first we have to find the max and smax of the array 
        int max=-1,smax=-1;

        for(int i=0;i<nums.size();i++)
        {
            if(max<nums[i])
            {
                smax=max;
                max=nums[i];
            }

            else if(smax<nums[i])
            {
                smax=nums[i];
            }
        }

        return (max-1)*(smax-1);
        
    }
};