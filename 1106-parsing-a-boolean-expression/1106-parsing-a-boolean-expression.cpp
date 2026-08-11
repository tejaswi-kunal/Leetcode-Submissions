class Solution {
public:
    bool parseBoolExpr(string s) 
    {
        stack<char>st;

        int i=0;
        while(i<s.size())
        {
            if(s[i]==',')
            {
                i++;
            }

            else if(s[i]=='&' || s[i]=='|' || s[i]=='!')
            {
                st.push(s[i]);
                i+=2;
            }

            else if(s[i]=='t' || s[i]=='f')
            {
                st.push(s[i]);
                i++;
            }

            else if(s[i]==')')
            {
                bool exp1=0,exp2=0;
                while(!st.empty() && (st.top()!='&' && st.top()!='|' && st.top()!='!'))
                {
                    if(st.top()=='t')
                    {
                        exp1=1;
                    }

                    else if(st.top()=='f')
                    {
                        exp2=1;
                    }

                    st.pop();
                }

                char op=st.top();
                st.pop();

                // now we have to check the result of the expression
                bool result;
                if(op=='&')
                {
                    if(!exp2)
                    {
                        result=1;
                    }

                    else
                    {
                        result=0;
                    }
                }

                else if(op=='|')
                {
                    if(exp1)
                    {
                        result=1;
                    }

                    else
                    {
                        result=0;
                    }
                }

                else
                {
                    if(exp1)
                    {
                        result=0;
                    }

                    else
                    {
                        result=1;
                    }
                }
                if(result)
                {
                    st.push('t');
                }

                else
                {
                    st.push('f');
                }
                i++;
            }
        }

        char ans=st.top();
        
        if(ans=='t')
        {
            return true;
        }

        else
        {
            return false;
        }

        return ans;
        
    }
};