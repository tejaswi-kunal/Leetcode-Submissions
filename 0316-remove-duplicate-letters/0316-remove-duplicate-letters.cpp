class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        stack<char>st;

        vector<int>last(26,-1);

        // first we have to store the last position of all the unique chracters in the string
        for(int i=s.size()-1;i>=0;i--)
        {
            if(last[s[i]-'a']==-1)
            {
                last[s[i]-'a']=i;
            }
        }

        vector<bool>taken(26,0);

        for(int i=0;i<s.size();i++)
        {
            if(!taken[s[i]-'a'])
            {
                while(!st.empty() && st.top()>s[i] && last[st.top()-'a']>i)
                {
                    // then we can remove the element 
                    taken[st.top()-'a']=0;
                    st.pop();
                }

                st.push(s[i]);
                taken[s[i]-'a']=1;
            }
        }

        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};