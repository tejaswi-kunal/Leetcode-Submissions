class Solution {
public:
    int captureForts(vector<int>& forts) 
    {
        int n=forts.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(forts[i]==-1)
            {
                count=1;
            }

            else if(count && forts[i]==0)
            {
                prefix[i]=prefix[i-1]+1;
            }

            else if(count && forts[i]==1)
            {
                prefix[i]=prefix[i-1];
                count=0;
            }
        }

        count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(forts[i]==-1)
            {
                count=1;
            }

            else if(count && forts[i]==0)
            {
                prefix[i]=prefix[i+1]+1;
            }

            else if(count && forts[i]==1)
            {
                prefix[i]=prefix[i+1];
                count=0;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(forts[i]==1)
            {
                ans=max(ans,max(prefix[i],suffix[i]));
            }
        }

        return ans;
    }
};