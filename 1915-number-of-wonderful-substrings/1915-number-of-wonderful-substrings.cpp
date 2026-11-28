class Solution {
public:
    using ll = long long;
    long long wonderfulSubstrings(string s) 
    {
        ll count = 0;
        int mask=0;

        // will keep the count of each valid mask
        unordered_map<int,ll>mp;
        mp[0]=1;

        for(int i=0;i<s.size();i++)
        {
            int bit = s[i]-'a';
            mask^=(1<<bit);

            // now we have to check for all the combinations 
            ll count1 = 0;

            if(mp.count(mask)!=0)
            count1+=mp[mask];

            for(int i=0;i<10;i++)
            {
                int mask1=mask^(1<<i);
                if(mp.count(mask1))
                {
                    count1+=mp[mask1];
                }
            }

            // update the map
            mp[mask]++;
            count+=count1;
        }

        return count;

    }
};