class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        // lets do the problem using the bit manipulation 
        int n=nums.size();
        int subseq=1<<n;

        vector<vector<int>>finalAns;
        for(int i=0;i<subseq;i++)
        {
            // each number will represent one of the possible subsets
            // now till how many bits we check each number 
            vector<int>ans;
            for(int j=0;j<n;j++)
            {
                if(i>>j&1)
                {
                    // check if jth bit is 1
                    ans.push_back(nums[j]);
                }
            }

            finalAns.push_back(ans);
        }

        return finalAns;
        
    }
};