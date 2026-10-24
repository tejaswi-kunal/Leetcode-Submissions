class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;

        for(int i=0;i<nums.size();i++)
        {
            int target=-nums[i];
            int start=i+1,end=nums.size()-1;

            while(start<end)
            {
                if(nums[start]+nums[end]==target)
                {
                    s.insert({nums[i],nums[start],nums[end]});
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

        for(auto &it : s)
        {
            ans.push_back(it);
        }

        return ans;
        
    }
};