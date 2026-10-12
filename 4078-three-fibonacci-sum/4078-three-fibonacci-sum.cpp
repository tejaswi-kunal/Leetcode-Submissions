class Solution {
public:
    bool threeFibonacciSum(int n) 
    {
        if(n==0 || n==1)
        {
            return false;
        }

        if(n%2!=0)
        {
            return 0;
        }

        n/=2;

        int curr=0,prev1=0,prev2=1;
        while(curr<n)
        {
            curr=prev1+prev2;

            if(curr==n)
            {
                return true;
            }

            prev1=prev2;
            prev2=curr;
        }

        return false;
        
    }
};