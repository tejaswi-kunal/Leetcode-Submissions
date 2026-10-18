class Solution {
public:
    bool comp(char c1,char c2)
    {
        if(c1+1==c2 || c2+1==c1)
        {
            return 1;
        }

        else if(c1=='a'&& c2=='z')
        {
            return 1;
        }

        else if(c1=='z' && c2=='a')
        {
            return 1;
        }

        return 0;
    }

    string resultingString(string s) 
    {
        stack<char>st;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && comp(st.top(),s[i]))
            {
                st.pop();
            }

            else
            {
                st.push(s[i]);
            }
        }

        // at last we have to form the string from the remaining characters 
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