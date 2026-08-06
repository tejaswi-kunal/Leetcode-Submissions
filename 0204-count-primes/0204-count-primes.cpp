class Solution {
public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                // we found a factor of n
                return 0;
            }
        }

        return 1;
    }

    int countPrimes(int n) 
    {
        if(n==0 || n==1 || n==2)
        {
            return 0;
        }
        vector<bool>prime(n,1);
        n--;
        prime[0]=0,prime[1]=0;

        // now we have to use the seive of eratos 
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i] && isPrime(i))
            {
                for(int j=2;i*j<=n;j++)
                {
                    prime[i*j]=0;
                }
            }
        }

        // count the numbers with prime tag
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(prime[i])
            {
                ans++;
            }
        }

        return ans;
        
    }
};