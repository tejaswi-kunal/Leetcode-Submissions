class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int m=n;
        int s=0,p=1;

        while(n)
        {
            int rem=n%10;
            n/=10;

            s+=rem;
            p*=rem;
        }

        if(m%(s+p)==0)
        {
            return true;
        }

        else
        {
            return false;
        }
        
    }
};