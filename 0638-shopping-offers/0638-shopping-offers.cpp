class Solution {
public:
    map<vector<int>,int>mp;
    int shoppingOffers(vector<int>& prices, vector<vector<int>>& special, vector<int>& needs) {
        mp.clear();
        return solve(needs,special,prices);
    }

    bool notNeg(vector<int>&nums)
    {
        for(auto it : nums)
        {
            if(it<0)
            {
                return 0;
            }
        }

        return 1;
    }

    bool checkNeeds(vector<int>&nums)
    {
        for(auto it: nums)
        {
            if(it > 0)
            {
                return 0;
            }
        }

        return 1;
    }

    int solve(vector<int>needs,vector<vector<int>>& special,vector<int>& prices)
    {
        
        if(checkNeeds(needs))
        {
            return 0;
        }

        if(mp.count(needs))
        {
            return mp[needs];
        }

        int ans=0;

        for(int i=0;i<prices.size();i++)
        {
            ans += needs[i]*prices[i];
        }

        // first we have to explore all the special offers
        for(auto &it : special)
        {
            vector<int>futureNeeds(needs.size());
            for(int i=0;i<prices.size();i++)
            {
                futureNeeds[i]=needs[i]-it[i];
            }

            if(notNeg(futureNeeds))
            {
                ans=min(ans,solve(futureNeeds,special,prices)+it[needs.size()]);
            }
        }

        return mp[needs] =  ans;
    }
};