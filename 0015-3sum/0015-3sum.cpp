class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int last_start=1e9,last_end=1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || (nums[i-1]!=nums[i]))
            {
                int target=-nums[i];
                int start=i+1,end=nums.size()-1;
                last_start=1e9,last_end=1e9;

                while(start<end)
                {
                    if(nums[start]+nums[end]==target)
                    {
                        if(last_start!=nums[start] && last_end!=nums[end])
                        {
                            ans.push_back({nums[i],nums[start],nums[end]});
                            last_start=nums[start],last_end=nums[end];
                        }

                        start++,end--;
                    }

                    else if(nums[start]+nums[end]>target)
                    {
                        end--;
                    }

                    else
                    {
                        start++;
                    }
                }
            }
        }

        return ans;
        
    }
};