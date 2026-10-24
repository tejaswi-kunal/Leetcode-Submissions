class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());

        int bestS=0,bestDist=1e9;

        for(int i=0;i<nums.size();i++)
        {
            int start=i+1,end=nums.size()-1;

            while(start<end)
            {
                int s=nums[i]+nums[start]+nums[end];
                int dist=abs(target-s);

                if(dist<bestDist)
                {
                    bestDist=dist;
                    bestS=s;
                }

                if(s==target)
                {
                    return s;
                }
                
                else if(s<target)
                {
                    start++;
                }

                else
                {
                    end--;
                }
            }
        }

        return bestS;
        
    }
};