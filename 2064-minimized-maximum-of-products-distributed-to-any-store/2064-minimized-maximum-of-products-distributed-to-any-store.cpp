class Solution {
public:
    using ll=long long;
    bool check(int ans,int n,vector<int>&q)
    {
        ll x=0;
        // find the number of store req according to the max no items we have decided for each store
        for(auto &it : q)
        {
            if(it%ans==0)
            {
                x+=(it/ans);
            }
            else
            {
                x+=(it/ans+1);
            }
        }

        if(x<=n)
        {
            return true;
        }

        return false;
    }

    int minimizedMaximum(int n, vector<int>& q) 
    {
        ll start=1;
        ll end=accumulate(q.begin(),q.end(),0*1LL);
        int ans=1e9;

        while(start<=end)
        {
            ll mid=start+(end-start)/2;

            if(check(mid,n,q))
            {
                ans=mid;

                // we have to minimize the ans
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