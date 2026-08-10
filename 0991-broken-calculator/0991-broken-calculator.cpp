class Solution {
public:
    int brokenCalc(int startVal, int target) 
    {
        int ans=0;
        while(startVal!=target)
        {
            if(target%2==0 && target>startVal)
            {
                target/=2;
                ans++;
            }

            else
            {
                target++;
                ans++;
            }
        }

        return ans;
        
    }
};