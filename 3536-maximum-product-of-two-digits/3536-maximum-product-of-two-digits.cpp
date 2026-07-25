class Solution {
public:
    int maxProduct(int n) 
    {
        // we have to find the max and second max of all the digits for max product

        int maxi=-1,smaxi=-1;

        while(n)
        {
            int digit=n%10;
            n/=10;

            // now we have to store these digits
            if(maxi<digit)
            {
                smaxi=maxi;
                maxi=digit;
            }

            else if(smaxi<digit)
            {
                smaxi=digit;
            }
        }

        return maxi*smaxi;
        
    }
};