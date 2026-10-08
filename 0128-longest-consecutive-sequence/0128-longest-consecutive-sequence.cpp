class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>s(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            int size=0;
            while(s.find(n)!=s.end())
            {
                if(mp.find(n)!=mp.end())
                {
                    size+=mp[n];
                    break;
                }

                else
                {
                    mp[n]=1;
                    size++;
                }
                n--;
            }

            ans=max(ans,size);
            mp[nums[i]]=size;
        }
        
        return ans;
    }
};