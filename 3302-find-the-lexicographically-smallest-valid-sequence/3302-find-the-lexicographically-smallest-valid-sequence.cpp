class Solution {
public:
    vector<int> validSequence(string s1, string s2) 
    {
        int n=s1.size();
        int m=s2.size();

        vector<int>suffix(n);

        int i=n-1,j=m-1;
        if(s1[i]==s2[j])
        {
            suffix[i]=1;
            j--;
        }
        i--;

        while(i>=0 && j>=0)
        {
            if(s1[i]==s2[j])
            {
                suffix[i]=suffix[i+1]+1;
                j--;
            }

            else
            {
                suffix[i]=suffix[i+1];
            }

            i--;
        }

        while(i>=0)
        {
            suffix[i]=suffix[i+1];
            i--;
        }

        i=0,j=0;
        vector<int>ans;
        bool canChange=true;
        while(i<n && j<m)
        {
            if(s1[i]==s2[j])
            {
                ans.push_back(i);
                j++;
            }

            else if((i+1<n && m-j-1<=suffix[i+1]) && canChange)
            {
                canChange=false;
                ans.push_back(i);
                j++;
            }

            i++;
        }

        if(j==m)
        {
            return ans;
        }

        vector<int>ans1;
        return ans1;
        
    }
};