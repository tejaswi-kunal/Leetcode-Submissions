class Solution {
public:
    bool check(int mid,vector<int>diff,vector<vector<int>>& q)
    {
        // now we have to verify if we can convert the array to zero array with mid no of operations 
        for(int i=0;i<mid;i++)
        {
            int l=q[i][0],r=q[i][1],val=q[i][2];

            diff[l]-=val;

            if(r+1<diff.size())
            diff[r+1]+=val;
        }

        // now we have to check if we able to make the zero array 
        if(diff[0]>0)
        {
            return 0;
        }
        for(int i=1;i<diff.size();i++)
        {
            diff[i]=diff[i]+diff[i-1];
            if(diff[i]>0)
            {
                return 0;
            }
        }

        return 1;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) 
    {
        // first we have to find the difference array of the given array 
        vector<int>diff(nums.size());
        diff[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            diff[i]=nums[i]-nums[i-1];
        }

        int ans=q.size()+1;
        int start=0,end=q.size();

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(check(mid,diff,q))
            {
                ans=mid;
                end=mid-1;
            }

            else
            {
                start=mid+1;
            }
        }
        if(ans<=q.size())
        return ans;

        return -1;
    }
};