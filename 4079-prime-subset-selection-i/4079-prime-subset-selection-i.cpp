class Solution {
public:
    vector<int> maxPrimes(int n, int s) 
    {
        vector<bool>isPrime(n+1,1);

        isPrime[0]=isPrime[1]=0;

        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {
                for(int j=2;i*j<=n;j++)
                {
                    isPrime[i*j]=0;
                }
            }
        }

        // now we have to find all the primes whose sum will be less than or equal to s
        int sum=0;
        int i=0;
        vector<int>ans;
        while(sum<s && i<n+1)
        {
            if(isPrime[i])
            {
                sum+=i;
                if(sum<=s)
                {
                    ans.push_back(i);
                }
            }

            i++;
            
        }

        return ans;
        
    }
};