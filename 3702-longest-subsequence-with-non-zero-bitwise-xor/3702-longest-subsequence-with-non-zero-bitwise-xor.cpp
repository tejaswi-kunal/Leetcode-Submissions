class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        bool flag=0;
        for(auto &it : nums)
        {
            if(it)
            {
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            return 0;
        }

        int ans=0,n=nums.size(),len=0;
        for(int i=0;i<n;i++)
        {
            ans^=nums[i];
        }

        if(ans)
        return n;

        else
        return n-1;
    }
};