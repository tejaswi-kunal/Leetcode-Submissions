class Solution {
public:
    bool isUgly(int n) 
    {
        // first we have to find all the prime factors of n
        if(n==1)
        {
            return 1;
        }

        if(n<=0)
        {
            return 0;
        }
        for(int i=2;i<=n;i++)
        {
            if(i>5)
            {
                return 0;
            }
            
            if(n%i==0) 
            {
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }

        return 1;
        
    }
};