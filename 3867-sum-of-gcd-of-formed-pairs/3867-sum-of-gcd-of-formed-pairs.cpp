class Solution {
public:
    int gcd(int a,int b)
    {
        if(!b)
        {
            return a;
        }

        return gcd(b,a%b);
    }

    long long gcdSum(vector<int>& nums) 
    {
        // first we have to form the maxi
        int n=nums.size();
        vector<int>maxi(n);
        
        maxi[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            maxi[i]=max(maxi[i-1],nums[i]);
        }

        // now we have to form perfixgcd
        vector<int>prefix(n);

        for(int i=0;i<n;i++)
        {
            if(maxi[i]>=nums[i])
            {
                prefix[i]=gcd(maxi[i],nums[i]);
            }

            else
            {
                prefix[i]=gcd(nums[i],maxi[i]);
            }
        }

        // now we have to sort it 
        sort(prefix.begin(),prefix.end());

        // now we have to find the final ans
        long long ans=0;

        int i=0,j=n-1;

        while(i<j)
        {
            ans+=gcd(prefix[j],prefix[i]);
            i++,j--;
        }

        return ans;
    }
};