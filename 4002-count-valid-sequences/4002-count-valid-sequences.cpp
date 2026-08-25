class Solution {
public:
    const int m=1e9+7;
    using ll=long long;
    vector<ll>fact;
    vector<ll>invFact;

    ll moduloExp(int n,int e)
    {
        ll base=n%m;
        ll exp=e;
        ll ans=1;

        while(exp)
        {
            if(exp&1)
            {
                ans=(ans*base)%m;
            }
            base=(base*base)%m;
            exp=exp>>1;
        }

        return ans;
    }

    ll nCr(int n,int r)
    {
        if(r<0 || n-r<0)
        {
            return 0;
        }
        return fact[n]*invFact[n-r]%m*invFact[r]%m;
    }

    int countValidSequences(int n, int k) 
    {
        int N=n+k-1;
        // first we have to precompute fact[i]%m upto n
        fact.resize(N+1);
        invFact.resize(N+1);

        fact[0]=1;
        for(int i=1;i<=N;i++)
        {
            fact[i]=(fact[i-1]*i)%m;
        }

        // now similarly we have to pre compute inverse fact 
        // first we will calculate the invFact of n ,then calculate others with help of it
        invFact[N]=moduloExp(fact[N],m-2);
        for(int i=N-1;i>=0;i--)
        {
            invFact[i]=(invFact[i+1]*(i+1))%m;
        }
        
        // now we have to calculate the total number of sequences of size k whose sum is n
        ll first=nCr(n-1,k-1);

        // also we have to caclulate the number of sequences whose sum is n but all the digits are also odd 
        // its not possible that all the members of seq are odd
        if((n-k)%2!=0)
        {
            return first;
        }

        ll second=nCr((n+k-2)/2,k-1);

        return (first-second+m)%m;
    }
};