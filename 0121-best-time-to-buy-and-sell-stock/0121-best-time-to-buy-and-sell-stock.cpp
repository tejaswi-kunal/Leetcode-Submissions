class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int>maxi(n);
        maxi[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1],nums[i]);
        }

        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans=max(maxi[i+1]-nums[i],ans);
        }

        return ans; 
    }
};