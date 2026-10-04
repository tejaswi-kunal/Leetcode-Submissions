class Solution {
public:
    int longestValidParentheses(string s) 
    {   
        int ans=0,len=0,curr=0;

        int open=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                open++;
                len++;
            }

            else
            {
                if(open)
                {
                    open--;
                    len++;

                    if(!open)
                    {
                        curr=len;
                        ans=max(ans,curr);
                    }
                }

                else
                {
                    open=0,len=0,curr=0;
                }
            }
        }

        int close=0;
        len=0,curr=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                close++;
                len++;
            }

            else 
            {
                if(close)
                {
                    close--;
                    len++;

                    if(!close)
                    {
                        curr=len;
                        ans=max(curr,ans);
                    }
                }

                else
                {
                    close=0,len=0,curr=0;
                }
            }
        }

        return ans;
        
    }
};