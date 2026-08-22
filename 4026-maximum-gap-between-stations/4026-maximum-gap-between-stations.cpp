class Solution {
public:
    int maximumGap(string skill, string st) 
    {
        // first we have to form the suffix sum
        int n=skill.size();
        int m=st.size();
        
        vector<int>suffix(m+1,0);
        vector<int>prefix(m);

        int i=n-1;
        for(int j=m-1;j>=0;j--)
        {
            if(i<0)
            {
                suffix[j]=suffix[j+1];
            }
            
            else if(st[j]==skill[i])
            {
                suffix[j]=suffix[j+1]+1;
                i--;
            }

            else
            {
                suffix[j]=suffix[j+1];
            }
        }

        // now we have to also form the prefix
        i=0;
        if(skill[i]==st[0])
        {
            prefix[i]=1;
            i++;
        }
        for(int j=1;j<m;j++)
        {
            if(i==n)
            {
                prefix[j]=prefix[j-1];
            }

            else if(skill[i]==st[j])
            {
                prefix[j]=prefix[j-1]+1;
                i++;
            }

            else
            {
                prefix[j]=prefix[j-1];
            }
        }


        // now we have to first and the last for each station 
        vector<int>p;
        vector<int>s;

        int j=0;

        while(j<m && prefix[j]==0){
            j++;
        }
        int c=prefix[j];
        while(j<m){
            int f=j;

            while(j<m && prefix[j]==c){
                j++;
            }
            if(j<m)
            c=prefix[j];

            p.push_back(f);   
        }

        c=suffix[0];
        j=0;
        while(j<m)
        {
            while(j<m && suffix[j]==c)
            {
                j++;
            }

            if(j<m)
            {
                c=suffix[j];
            }
            int l=j-1;
            s.push_back(l);
        }

        i=1;
        int ans=0;
        while(i<n)
        {
            ans=max(ans,s[i]-p[i-1]);
            i++;
        }

        return ans;
        
    }
};