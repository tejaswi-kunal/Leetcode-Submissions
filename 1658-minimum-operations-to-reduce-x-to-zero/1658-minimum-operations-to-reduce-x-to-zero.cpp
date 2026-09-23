class Solution {
public:

    int binarySearch(int start,int end,vector<int>&arr,int target)
    {
        int mid;

        while(start<=end)
        {
            mid=start+(end-start)/2;

            if(arr[mid]==target)
            {
                return mid;
            }

            else if(arr[mid]<target)
            {
                start=mid+1;
            }

            else
            {
                end=mid-1;
            }
        }

        return -1;
    }

    int minOperations(vector<int>& nums, int x) 
    {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());

        // calculation of prefix and suffix sum
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }

        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+nums[i];
        }

        bool isPst=0;
        for(int i=0;i<nums.size();i++)
        {
            if(prefix[i]>=x)
            {
                isPst=1;
                break;
            }
        }

        if(isPst=0)
        {
            return -1;
        }

        int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX,ans4=INT_MAX;

        // ans1
        for(int i=0;i<nums.size();i++)
        {
            if(prefix[i]==x)
            {
                ans1=i+1;
                break;
            }
        }

        // ans2
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(suffix[i]==x)
            {
                ans2=nums.size()-i;
            }
        }

        // ans3
        int index=0;
        reverse(suffix.begin(),suffix.end());
        while(index<nums.size() && prefix[index]<x)
        {
            int suffix_index=binarySearch(0,nums.size()-(index+2),suffix,x-prefix[index]);

            if(suffix_index!=-1)
            ans3=min(ans3,index+suffix_index+2);

            index++;
        }

        // ans4
        index=0;
        while(index<nums.size() && suffix[index]<x)
        {
            int prefix_index=binarySearch(0,nums.size()-(index+2),prefix,x-suffix[index]);

            if(prefix_index!=-1)
            {
                ans4=min(ans4,index+prefix_index+2);
            }

            index++;
        }

        int ans=min(ans1,min(ans2,min(ans3,ans4)));

        if(ans==INT_MAX)
        {
            return -1;
        }

        return ans;
        
    }
};