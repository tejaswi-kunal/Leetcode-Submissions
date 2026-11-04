class Solution {
public:
    string maximumNumber(string s, vector<int>& change) 
    {
        int i=0;
        while(i<s.size())
        {
            if(s[i]-'0'<change[s[i]-'0'])
            {
                while(i<s.size() && s[i]-'0'<=change[s[i]-'0'])
                {
                    s[i]=change[s[i]-'0']+'0';
                    i++;
                }
                return s;
            }

            else
            i++;
        }

        return s;
        
    }
};