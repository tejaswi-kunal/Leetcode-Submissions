class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        vector<int>nums(s.size());
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[i]=s[i]-'0';
        }

        // now we have to find the largest number to the left of a number 
        pair<int,int> maxi={0,-1};
        vector<pair<int,int>>suff(n);
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>maxi.first)
            {
                maxi.first=nums[i];
                maxi.second=i;
            }
            suff[i]=maxi;
        }

        int ans=0;
        int k=1;
        for(int i=0;i<n;i++)
        {
            ans*=10;
            if(nums[i]<suff[i].first && k)
            {
                k=0;
                ans+=suff[i].first;
                nums[suff[i].second]=nums[i];
            }
            else
            {
                ans+=nums[i];
            }
        }

        return ans;
        
    }
};