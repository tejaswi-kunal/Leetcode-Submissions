class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        int first=0,second=1,maxFreq=1;

        while(second<nums.size())
        {
            if((nums[second]-nums[second-1])<=k/(second-first))
            {
                k-=(nums[second]-nums[second-1])*(second-first);
                second++;
                maxFreq=max(maxFreq,second-first);
            }

            else
            {
                k+=nums[second-1]-nums[first];
                first++;

                if(first==second)
                {
                    second++;
                }
            }
        }

        return maxFreq;
    }
};