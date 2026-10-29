class Solution {
public:
    int minimumTime(string s) 
    {
        int n=s.size();
        int pref=0;
        int ans=1e9;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                pref=min(i+1,pref+2);
            }

            ans=min(ans,pref+n-i-1);
        }

        return ans;

        
    }
};