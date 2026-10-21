class Solution {
public:
    using ll=long long;
    ll dp[1001][501][3];
    bool visited[1001][501][3];
    
    long long maximumProfit(vector<int>& prices, int k) {
        memset(visited,0,sizeof(visited));

        return solve(0,k,0,prices);
    }

    ll solve(int i,int k,int choice,vector<int>&nums)
    {
        if(i==nums.size())
        {
            if(choice==0)
            {
                return 0;
            }

            else
            {
                return -1e16;
            }
        }

        if(k==0)
        {
            if(choice==0)
            {
                return 0;
            }

            else
            {
                return -1e16;
            }
        }

        if(visited[i][k][choice])
        {
            return dp[i][k][choice];
        }

        ll c1=0,c2=0,c3=0;

        if(choice==0)
        {
            c1=-nums[i]+solve(i+1,k,2,nums);
            c2=nums[i]+solve(i+1,k,1,nums);
            c3=solve(i+1,k,0,nums);

            visited[i][k][choice]=1;
            return dp[i][k][choice]=max({c1,c2,c3});
        }

        else if(choice==1)
        {
            c1=-nums[i]+solve(i+1,k-1,0,nums);
            c2=solve(i+1,k,1,nums);
        }

        else
        {
            c1=nums[i]+solve(i+1,k-1,0,nums);
            c2=solve(i+1,k,2,nums);
        }

        visited[i][k][choice]=1;
        return dp[i][k][choice]=max(c1,c2);
    }
};