class Solution {
public:
    using ll=long long;
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) 
    {
        int n=monsters.size();
        // we have to determine the power which will be available to us while fighting the ith monster
        // first we have to build the difference array 
        vector<ll>diff(n,0);

        for(auto &it : boosts)
        {
            diff[it[0]]=diff[it[0]] + it[2];

            if(it[1]+1<n)
            {
                diff[it[1]+1]=diff[it[1]+1]-it[2];
            }
        }

        // now we have to build the power array 
        vector<ll>power(n,0);
        power[0]=diff[0];

        for(int i=1;i<n;i++)
        {
            power[i]=power[i-1]+diff[i];
        }

        // now we have determine the minimum strength req to defeat the ith monster
        ll s=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(power[i]<monsters[i])
            {
                // then we require some previous strength
                ans=s+(monsters[i]-power[i]);
            }

            s+=monsters[i];
        }

        return ans;
        
    }
};