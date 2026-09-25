class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        // space optimize it  
        int n=nums.size();

        int ans=nums[0];
        int prev=nums[0],curr;

        for(int i=1;i<n;i++)
        {
            curr=max(prev+nums[i],nums[i]);
            ans=max(curr,ans);

            prev=curr;
        }

        return ans;
        
    }
};