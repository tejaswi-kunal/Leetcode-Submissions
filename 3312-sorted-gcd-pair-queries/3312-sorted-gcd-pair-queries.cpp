class Solution {
public:
    using ll = long long;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
    {
        // first we have to calculate the maximum of all elements 
        int maxi=-1;
        int idx=max_element(nums.begin(),nums.end())-nums.begin();
        maxi=nums[idx];

        vector<ll>freq(maxi+1,0);

        for(auto it : nums)
        {
            freq[it]++;
        }

        // now we have to calculate the gcd count for each i 
        vector<ll>gcdCount(maxi+1,0);
        // it will contain the count of number of pairs whose gcd is i
        for(int i=maxi;i>=1;i--)
        {
            ll count=0,alreadyCounted=0;
            for(int j=i;j<=maxi;j=j+i)
            {
                count+=freq[j];
                alreadyCounted+=gcdCount[j];
            }

            ll pairs=(count)*(count-1)/2 - alreadyCounted;
            gcdCount[i]=pairs;
        }

        // now we have to return the ith largest gcd
        // for this we will use the gcd count --> prefix sum + binary serach
        
        for(int i=1;i<gcdCount.size();i++)
        {
            gcdCount[i]=gcdCount[i-1]+gcdCount[i];
        }

        // suppose it wants kth largest gcd -> so we have to return i whose gcdCount[i]>k
        vector<int>output;
        for(auto it : queries)
        {
            int ans=upper_bound(gcdCount.begin(),gcdCount.end(),it)-gcdCount.begin();
            output.push_back(ans);
        }

        return output;
        
    }
};