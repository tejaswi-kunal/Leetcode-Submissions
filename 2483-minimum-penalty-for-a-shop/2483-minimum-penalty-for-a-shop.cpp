class Solution {
public:
    int bestClosingTime(string cust) 
    {
        int n=cust.size();

        vector<int>pref(n);
        vector<int>suff(n);

        // first we have to calculate the prefix and suffix
        int prefix=0;
        for(int i=0;i<n;i++)
        {
            if(cust[i]=='N')
            {
                prefix++;
            }
            pref[i]=prefix;
        }

        int suffix=0;
        for(int i=n-1;i>=0;i--)
        {
            if(cust[i]=='Y')
            {
                suffix++;
            }
            suff[i]=suffix;
        }

        // now we have to calculate the most optimized index
        int penalty=1e9;
        int ans=-1;
        for(int j=0;j<=n;j++)
        {
            int i=j-1;
            int k=j;

            int p1=0,p2=0;

            if(i>=0)
            p1=pref[i];

            if(k<n)
            p2=suff[k];

            if(p1+p2<penalty)
            {
                penalty=p1+p2;
                ans=j;
            }
        }
        return ans;

        
    }
};