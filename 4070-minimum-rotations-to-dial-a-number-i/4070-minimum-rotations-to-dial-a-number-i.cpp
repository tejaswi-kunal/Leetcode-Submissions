class Solution {
public:
    int minRotations(string s) 
    {
        int ans=0;
        string prev="0";
        for(int i=0;i<s.size();i++)
        {
            int first=abs(s[i]-prev[0]);
            ans+=min(first,abs(9-first+1));
            prev[0]=s[i];
        }

        return ans;
        
    }
};