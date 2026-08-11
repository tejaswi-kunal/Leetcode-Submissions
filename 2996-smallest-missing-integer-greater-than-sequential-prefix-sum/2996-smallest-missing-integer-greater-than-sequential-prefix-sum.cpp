class Solution {
public:
    int missingInteger(vector<int>& nums) 
    {
        int prefix=nums[0];
        int ele=nums[0];

        if(nums.size()==1)
        {
            return nums[0]+1;
        }

        int i=1;
        while(i<nums.size() && nums[i]==ele+1)
        {
            prefix+=nums[i];
            ele=nums[i];
            i++;
        }

        vector<int>mp(51,0);

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=1;
        }


       int j=prefix;
       while(true)
       {
            if(j<=50  && mp[j])
            {
                j++;
                continue;
            }
            
            return j;
       }

       return -1;
    }
};