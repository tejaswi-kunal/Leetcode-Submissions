class Solution {
public:
    bool stoneGameIX(vector<int>& nums) 
    {
        // first we have to find the count of all remainders 0,1,2
        int n=nums.size();
        int r0=0,r1=0,r2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%3==0)
            {
                r0++;
            }

            else if(nums[i]%3==1)
            {
                r1++;
            }

            else
            {
                r2++;
            }
        }   

        // if the count of 0 is even then nothing happens
        if(r0%2==0)
        {
            if((r1>=1 && r2>=1) && (r1>=r2 || r2>=r1))
            {
                return 1;
            }
        }

        // if count of 0 is odd then turn changes
        else if(abs(r1-r2)>=3)
        {
            return  1;
        }
        
        return 0;
    }
};