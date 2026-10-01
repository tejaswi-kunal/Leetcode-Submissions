class Solution {
public:
    bool isValid(string s)
    {
        stack<char>st;

        int index=0;
        while(index<s.size())
        {
            //opening
            if(s[index]=='(' || s[index]=='{' || s[index]=='[')
            {
                st.push(s[index]);
            }

            //closing
            else
            {
                //check if the stack is empty
                if(st.empty())
                {
                    return 0;
                }

                //check the each bracket seperately
                //()
                else if(s[index]==')')
                {
                    if(st.top()!='(')
                    {
                        return 0;
                    }

                    else
                    {
                        st.pop();
                    }
                }
                //{}
                else if(s[index]=='}')
                {
                    if(st.top()!='{')
                    {
                        return 0;
                    }

                    else
                    {
                        st.pop();
                    }
                }

                //[]
                else
                {
                    if(st.top()!='[')
                    {
                        return 0;
                    }

                    else
                    {
                        st.pop();
                    }
                }
            }
            index++;
        }
        return st.empty();
    }
};