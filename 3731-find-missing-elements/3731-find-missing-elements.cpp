class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        vector<int>mp(101,0);

        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        for(auto &it : nums)
        {
            mp[it]=1;
        }

        vector<int>ans;
        for(int i=mini+1;i<=maxi;i++)
        {
            if(!mp[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};