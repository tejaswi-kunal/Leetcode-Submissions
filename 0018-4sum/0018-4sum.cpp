class Solution {
public:
    using ll=long long;
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        set<vector<int>>s;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                ll t=(1LL)*target-nums[i]-nums[j];
                int start=j+1,end=nums.size()-1;

                while(start<end)
                {
                    if(nums[start]+nums[end]==t)
                    {
                        s.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++,end--;
                    }
                    
                    else if(nums[start]+nums[end]<t)
                    {
                        start++;
                    }

                    else
                    {
                        end--;
                    }
                }
            }
        }

        vector<vector<int>>ans;
        for(auto &it : s)
        {   
            ans.push_back(it);
        }

        return ans;
        
    }
};