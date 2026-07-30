class Solution {
public:
    int minimumPushes(string word) 
    {
        int n=word.size();

        int time=1,cost=0;

        while(n>0)
        {
            if(n<=8)
            {
                cost+=n*time;
                n=0;
            }

            else
            {
                cost+=8*time;
                time++;
                n-=8;
            }
        }

        return cost;
        
    }
};