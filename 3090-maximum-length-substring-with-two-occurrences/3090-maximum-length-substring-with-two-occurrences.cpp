class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        vector<int>mp(26,0);

        int first=0,second=0;
        int ans=0;

        while(second<s.size())
        {
            mp[s[second]-'a']++;

            while(mp[s[second]-'a']>2)
            {
                mp[s[first]-'a']--;
                first++;
            }

            ans=max(ans,second-first+1);
            second++;
        } 

        return ans;       
    }
};