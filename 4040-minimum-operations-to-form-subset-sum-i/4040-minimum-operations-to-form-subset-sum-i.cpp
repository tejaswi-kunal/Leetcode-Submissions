class Solution {
public:
    int minOperations(vector<int>& nums, int sum) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));

        // first we have to define the base case
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=1e8;
        }

        int f=nums[0];
        int c=0;
        while(f<=sum)
        {
            dp[0][f]=c;
            c++;
            f*=2;
        }

        f=nums[0]/2;
        c=1;
        while(f>0)
        {
            if(f<=sum)
            dp[0][f]=c;
            
            f/=2;
            c++;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int c1=1e8,c2=1e8,c3=1e8;
                int curr=nums[i];
                int count=0;
                while(curr<=j)
                {
                    c1=min(c1,dp[i-1][j-curr]+count);
                    count++;
                    curr*=2;
                }

                curr=nums[i]/2;
                count=1;
                while(curr>0)
                {
                    if(j-curr>=0)
                    {
                        c2=min(c2,dp[i-1][j-curr]+count);
                    }
                    curr/=2;
                    count++;
                }

                c3=dp[i-1][j];

                dp[i][j]=min({c1,c2,c3});
            }
        }

        if(dp[n-1][sum]<1e8)
        {
            return dp[n-1][sum];
        }

        return -1;
        
    }
};