class Solution {
public:
    bool checkValidString(string s) 
    {
        int o=0,e=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                o++;
            }

            else if(s[i]=='*')
            {
                e++;
            }

            else 
            {
                if(o)
                {
                    o--;
                }

                else if(e)
                {
                    e--;
                }

                else
                {
                    return 0;
                }
            }
        }

        if(o>e)
        {
            return 0;
        }

        // now second round 
        int c=0;
        e=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                c++;
            }

            else if(s[i]=='*')
            {
                e++;
            }

            else
            {
                if(c)
                {
                    c--;
                }

                else if(e)
                {
                    e--;
                }

                else
                {
                    return 0;
                }
            }
        }

        if(c>e)
        {
            return 0;
        }

        return 1;
        
    }
};