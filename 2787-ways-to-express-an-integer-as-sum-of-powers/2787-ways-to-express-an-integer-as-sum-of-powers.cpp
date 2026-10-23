class Solution {
public:
    int dp[305][305];
    const int mod=int(1e9+7);
    int numberOfWays(int n, int x) 
    {
        memset(dp,-1,sizeof(dp));

        int idx=pow(n,1.0/x);
        idx++;
        return solve(idx,n,x);
    }

    int solve(int i,int target,int x)
    {
        if(!target)
        {
            return 1;
        }

        if(i==1)
        {
            return target==i;
        }

        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }

        // we have choice of taking i and of not taking i
        int num=pow(i,x);
        int c1=0,c2=0;
        if(target-num>=0)
        {
            c1=solve(i-1,target-num,x);
        }

        c2=solve(i-1,target,x);

        return dp[i][target] = (c1+c2)%mod;
    }

};