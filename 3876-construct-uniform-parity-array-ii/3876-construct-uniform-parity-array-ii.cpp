class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        // first check if all the elements are odd or even 
        int count1=0,count2=0;
        
        int mini=1e9+7;
        for(auto &it : nums1)
        {
            if(it%2==0)
            {
                count1++;
            }

            else
            {
                mini=min(mini,it);
                count2++;
            }
        }

        if(count1==nums1.size() || count2==nums1.size())
        {
            return 1;
        }

        for(auto &it: nums1)
        {
            if(it%2==0)
            {
                if(it-mini<1)
                {
                    return 0;
                }
            }
        }

        return 1;
    }
};