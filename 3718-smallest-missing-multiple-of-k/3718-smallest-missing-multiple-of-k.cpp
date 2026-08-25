class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        unordered_set<int>s(nums.begin(),nums.end());

        // now we have to form all the multiples of k
        int i=1;
        while(true)
        {
            if(s.find(k*i)==s.end())
            {
                return k*i;
            }
            i++;
        }

        return -1;
        
    }
};