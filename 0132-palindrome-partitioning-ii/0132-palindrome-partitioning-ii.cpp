class Solution {
public:
    int minCut(string s) 
    {
        int n=s.size();
        vector<int>dp(n+1);

        dp[n]=0;

        for(int i=n-1;i>=0;i--)
        {
            int mini=1e9;
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(i,j,s))
                {
                    mini=min(mini,dp[j+1]+1);
                }
            }

            dp[i]=mini;
        }

        return dp[0]-1;
        
    }

    bool isPalindrome(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return 0;
            }
            i++;
            j--;
        }

        return 1;
    }
};