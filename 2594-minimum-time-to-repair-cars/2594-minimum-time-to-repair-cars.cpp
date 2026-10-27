class Solution {
public:
    using ll=long long;

    bool check(ll ans,vector<int>ranks,int cars)
    {
        // find the number of cars we can repair in the time ans
        ll n=0;

        for(int i=0;i<ranks.size();i++)
        {
            ll x=ans/ranks[i];
            n=n+1LL*sqrt(x);
        }

        if(n>=cars)
        {
            return 1;
        }

        return 0;
    }

    long long repairCars(vector<int>& ranks, int cars) 
    {
        int maxi=*max_element(ranks.begin(),ranks.end());
        ll start=1,end=1LL*cars*cars*maxi;

        ll ans=end;

        while(start<=end)
        {
            ll mid=start+(end-start)/2;

            if(check(mid,ranks,cars))
            {
                ans=mid;
                end=mid-1;
            }

            else
            {
                start=mid+1;
            }
        }

        return ans;
        
    }
};