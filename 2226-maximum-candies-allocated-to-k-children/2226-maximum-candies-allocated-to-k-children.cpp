class Solution {
public:
    using ll=long long;

    bool check(ll mid,vector<int>&candies,ll k)
    {
        // we have to check if we can allocate candies to k childres if the max count is mid;
        ll count=0;

        for(int i=0;i<candies.size();i++)
        {
            ll curr=candies[i];

            if(mid)
            count+=(curr/mid);
        }

        if(count>=k)
        {
            return 1;
        }

        return 0;
    }

    int maximumCandies(vector<int>& candies, long long k) 
    {
        ll end=*max_element(candies.begin(),candies.end());
        ll start=1,ans=0;

        if(candies.size()==1 && k==1)
        {
            return candies[0];
        }

        while(start<=end)
        {
            ll mid=start+(end-start)/2;

            if(check(mid,candies,k))
            {
                ans=mid;
                start=mid+1;
            }

            else
            {
                end=mid-1;
            }
        }

        return ans;
        
    }
};