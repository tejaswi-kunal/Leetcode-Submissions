class Solution {
public:
    string smallestPalindrome(string s) 
    {
        vector<int>freq(26,0);

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }

        // now we have to build the string using the freq;
        string s1,s2,s3;
        for(int i=0;i<26;i++)
        {
            if(freq[i]%2==0)
            {
                // we have to store it in both strings 
                int count=freq[i]/2;
                while(count)
                {
                    s1+='a'+i;
                    s2+='a'+i;
                    count--;
                }
            }

            else 
            {
                int count=freq[i]/2;
                while(count)
                {
                    s1+='a'+i;
                    s2+='a'+i;
                    count--;
                }

                s3+='a'+i;
            }
        }

        reverse(s2.begin(),s2.end());

        return s1+s3+s2;
        
    }
};