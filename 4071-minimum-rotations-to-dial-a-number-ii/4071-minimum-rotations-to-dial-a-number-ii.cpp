class Solution {
public:
    int solve(char digit1,char digit2)
    {
        int first=abs(digit1-digit2);
        int result=min(first,9-first+1);

        return result;
    }

    int minRotations(int n, string s) 
    {
        // first we have to find the actual cost 
        int actual=0;
        char prev='0';
        for(int i=0;i<s.size();i++)
        {
            actual+=solve(prev,s[i]);
            prev=s[i];
        }

        // now we have to perform the optimization
        char last=s[n-1];
        int ans=actual;
        prev='0';
        for(int i=0;i<n;i++)
        {
            ans=min(ans,actual+solve(prev,last)-solve(prev,s[i]));
            prev=s[i];
        }

        return ans;
    }
};