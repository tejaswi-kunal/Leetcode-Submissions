class Solution {
public:
    using ll= long long;
    bool isPrime(ll n)
    {
        if(n==1 || n==0)
        {
            return 0;
        }
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }

        return 1;
    }
    long long sumOfLargestPrimes(string str) 
    {
        ll f=0,s=0,t=0;
        for(int i=0;i<str.size();i++)
        {
            for(int j=i;j<str.size();j++)
            {
                ll n=stoll(str.substr(i,j-i+1));
                if(isPrime(n))
                {
                    if(n>f)
                    {
                        t=s;
                        s=f;
                        f=n;
                    }

                    else if(n>s && n!=f)
                    {
                        t=s;
                        s=n;
                    }

                    else if(n>t && n!=s && n!=f)
                    {
                        t=n;
                    }
                }
            }
        }

        return f+s+t;
        
    }
};