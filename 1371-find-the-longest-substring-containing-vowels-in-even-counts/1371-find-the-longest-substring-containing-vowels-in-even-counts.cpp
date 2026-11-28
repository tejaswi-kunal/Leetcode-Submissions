class Solution {
public:
    int isVowel(char c)
    {
        if(c=='a')
        return 0;
        
        else if(c=='e')
        return 1;

        else if(c=='i')
        return 2;

        else if(c=='o')
        return 3;

        else if(c=='u')
        return 4;

        return -1;
    }


    int findTheLongestSubstring(string s) 
    {
        int mask=0;
        unordered_map<int,int>mp;
        mp[0]=-1;

        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            int check=isVowel(s[i]);
            if(check!=-1)
            {
                mask^=(1<<check);
            }

            if(mp.find(mask)!=mp.end())
            {
                ans=max(ans,i-mp[mask]);
            }
            else
            {
                mp[mask]=i;
            }
        }

        return ans;
        
    }
};