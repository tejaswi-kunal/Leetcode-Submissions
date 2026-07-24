class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int mini=INT_MAX;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]==nums[j] && nums[j]==nums[k])
                    {
                        mini=min(mini,abs(j-i)+abs(k-j)+abs(k-i));
                    }
                }
            }
        }

        // now we return min of all the triplets of diffrent number
        if(mini==INT_MAX)
        {
            return -1;
        }
        return mini;
    }
};