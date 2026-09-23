class Solution {
public:
    int hIndex(vector<int>& c) 
    {
        int n=c.size();
        vector<int>suffix(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(c[i]>n)
            {
                suffix[n]++;
            }

            else
            {
                suffix[c[i]]++;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            suffix[i]+=suffix[i+1];
        }

        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(i<=suffix[i])
            {
                ans=max(ans,i);
            }
        }

        return ans;
        
    }
};