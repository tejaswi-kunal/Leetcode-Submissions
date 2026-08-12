class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int first=0,second=0,len=0;

        unordered_map<int,int>mp;

        while(first<nums.size())
        {
            mp[nums[first]]++;
            while(mp[nums[first]]>k)
            {
                //if it is equal to k then ,if we add nums[first] to the window then it will become greater than k
                //so we have to decrease the window
                mp[nums[second]]--;
                second++;
            }

            len=max(len,first-second+1);

            first++;
        }
        
        return len;
    }
};