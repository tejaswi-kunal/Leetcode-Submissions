class Solution {
public:

    bool comp(string &s1,string &s2)
    {
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i])
            {
                continue;
            }

            else if(s1[i]>s2[i])
            {
                return 1;
            }

            else 
            {
                return 0;
            }
        }

        return 0;
    }
    string shortestBeautifulSubstring(string s, int k) 
    {
        int n=s.size();
        int first=0,second=0;
        int len=1000;
        int count=0;
        string ans;
        while(second<n)
        {
            while(first<second && count==k)
            {
                string str=s.substr(first,second-first);
                if(len>second-first)
                {
                    len=second-first;
                    ans=str;
                }

                else if(len==second-first)
                {
                    if(comp(ans,str))
                    {
                        ans=str;
                    }
                }
                if(s[first]=='1')
                {
                    count--;
                }
                first++;
            }

            if(s[second]=='1')
            {
                count++;
            }

            second++;
        }

        while(first<second && count==k)
        {
            string str=s.substr(first,second-first);
            if(len>second-first)
            {
                len=second-first;
                ans=str;
            }

            else if(len==second-first)
            {
                if(comp(ans,str))
                {
                    ans=str;
                }
            }
            if(s[first]=='1')
            {
                count--;
            }
            first++;
        }
        
        return ans;
    }
};