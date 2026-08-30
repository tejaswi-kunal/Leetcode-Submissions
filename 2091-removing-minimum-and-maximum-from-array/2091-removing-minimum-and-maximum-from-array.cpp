class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n=nums.size();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        
        int i=min(maxi,mini);
        int j=max(maxi,mini);
        
        int left = j + 1;
        int right = n - i;
        int both = (i + 1) + (n - j);
        return min({left, right, both});
        
    }
};