class Solution {
public:
    using pii=pair<int,int>;

    int digitSum(int n)
    {
        int s=0;
        while(n>0)
        {
            int rem=n%10;
            n/=10;

            s+=rem;
        }

        return  s;
    }

    int minSwaps(vector<int>& nums) 
    {
        int n=nums.size();
        vector<pii>arr(n);

        for(int i=0;i<n;i++)
        {
            arr[i] = {nums[i], digitSum(nums[i])};
        }

        sort(arr.begin(),arr.end(),[](pair<int, int> a, pair<int, int> b) {

            if(a.second!=b.second)
            return a.second < b.second;

            else
            return a.first<b.first;
        });

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }

        int count =0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].first!=nums[i])
            {
                int j = mp[arr[i].first];
                swap(nums[i], nums[j]);

                mp[nums[i]] = i;
                mp[nums[j]] = j;

                count++;
            }
        }
        return count;
        
    }
};