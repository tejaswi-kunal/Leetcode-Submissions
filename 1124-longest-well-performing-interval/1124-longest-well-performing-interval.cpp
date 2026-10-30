class Solution {
public:
    int longestWPI(vector<int>& nums) 
    {
        int pref=0;
        int n=nums.size();

        vector<int>p(n,0);

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=8)
            {
                pref--;
            }
            else
            {
                pref++;
            }
            p[i]=pref;

            // now we have to find the longest good interval wrt to this interval 
            // pref[r]>pref[l-1]
            for(int j=i-1;j>=0;j--)
            {
                if(pref-p[j]>0)
                {
                    ans=max(ans,i-j);
                }
            }

            if(pref>0)
            {
                ans=i+1;
            }
        }

        return ans;
        
    }
};