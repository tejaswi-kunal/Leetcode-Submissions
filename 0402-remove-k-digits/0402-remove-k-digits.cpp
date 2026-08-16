class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(num.size()==k)
        {
            return "0";
        }
        stack<char>st;

        int i=0,n=num.size();
        while(i<n)
        {
            while(!st.empty() && st.top()>num[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }

        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }

        // now we have to form back the string 
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        // also we have to emove the trailing zeros
        i=0;
        while(i<ans.size() && ans[i]=='0')
        {
            i++;
        }

        string finalAns;
        while(i<ans.size())
        {
            finalAns+=ans[i];
            i++;
        }

        if(finalAns.size()>0)
        return finalAns;

        return "0";
        
    }
};