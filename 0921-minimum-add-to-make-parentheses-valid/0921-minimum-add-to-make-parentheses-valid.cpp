class Solution {
public:
    int minAddToMakeValid(string s)
    {
        //now lets try this question without using stack
        int index=0;
        int left=0,minAdd=0;

        while(index<s.size())
        {
            if(s[index]=='(')
            {
                left++;
            }

            else
            {
                if(left==0)
                {
                    minAdd++;
                }

                else 
                {
                    left--;
                }
            }
            index++;
        }
        return minAdd+left;
    }
};