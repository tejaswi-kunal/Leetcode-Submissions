class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        // first lets try the brute force 
        vector<int>mp(101,0);

        for(int i=1;i<=9;i++)
        {
            mp[i]=i;
        }

        int i=11,k=1;

        while(i<100)
        {
            for(int j=1;j<=9;j++)
            {
                mp[i]=k*j;
                i++;
            }

            k++;
            i++;
        }
        
        // find the first number >=n 
        for(int l=n;l<=100;l++)
        {
            if(mp[l]%t==0)
            {
                return l;
            }
        }

        return -1;
        
    }
};