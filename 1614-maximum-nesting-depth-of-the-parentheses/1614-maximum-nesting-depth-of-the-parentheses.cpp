class Solution {
public:
    int maxDepth(string s) 
    {
        //here we have to just keep track when a open bracket starts and ends
        int count=0,ans=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                count++;
            }

            else if(s[i]==')')
            {
                count--;
            }

            ans=max(ans,count);
        }
        
        return ans;
    }
};