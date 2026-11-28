class Solution {
public:
    int longestAwesome(string s) 
    {
        int mask=0;
        unordered_map<int,int>mp;

        mp[0]=-1;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            // first we have to update the mask
            int bit=s[i]-'0';
            mask^=(1<<bit);

            // now we have to find the max length of all the valid combinations 
            if(mp.count(mask)!=0)
            ans=max(ans,i-mp[mask]);

            else
            mp[mask]=i;

            for(int j=0;j<10;j++)
            {
                int mask1=mask^(1<<j);
                if(mp.count(mask1))
                {
                    ans=max(ans,i-mp[mask1]);
                }
            }
        }
        

        return ans;
    }
};