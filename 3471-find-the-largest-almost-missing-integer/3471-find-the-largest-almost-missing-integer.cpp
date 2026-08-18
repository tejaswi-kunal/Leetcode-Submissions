class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }

        if(k==nums.size())
        {
            // them we have to return the max
            return *max_element(nums.begin(),nums.end());
        }

        vector<int>mp(51);

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        if(k==1)
        {
            // return the max element with single appearence 
            for(int i=50;i>=0;i--)
            {
                if(mp[i]==1)
                {
                    return i;
                }
            }
        }

        int first=nums[0],second=nums[n-1];

        if(first==second && k<=1)
        {
            return -1;
        }

        // now we have to check if any of them appears more than once
        bool f=0,s=0;

        if(mp[first]>1)
        {
            f=1;
        }
        if(mp[second]>1)
        {
            s=1;
        }
        if(!f && !s)
        {
            return max(first,second);
        }

        else if(!f)
        {
            return first;
        }

        else if(!s)
        {
            return second;
        }

        else
        {
            return -1;
        }
        
    }
};