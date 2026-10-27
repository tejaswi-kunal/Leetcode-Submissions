class Solution {
public:
    using ll=long long;
    bool check(ll mid, ll index, int maxSum, int n)
    {
        ll s1 = 0, s2 = 0;

        ll len1 = n - index - 1;

        if (len1 >= mid - 1)
        {
            s1 = mid * (mid - 1) / 2;
            s1 += len1 - (mid - 1);
        }
        else
        {
            s1 = mid * (mid - 1) / 2;
            s1 -= (mid - 1 - len1) * (mid - len1) / 2;
        }

        ll len2 = index;

        if (len2 >= mid - 1)
        {
            s2 = mid * (mid - 1) / 2;
            s2 += len2 - (mid - 1);
        }
        else
        {
            s2 = mid * (mid - 1) / 2;
            s2 -= (mid - 1 - len2) * (mid - len2) / 2;
        }

        return s1 + s2 + mid <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) 
    {
        int start=maxSum/n;
        int end=maxSum;
        int ans=start;

        while(start<=end)
        {
            // select the maximized nums[index]
            int mid=start+(end-start)/2;

            // now we have to check if we can satisfy the other conditions 
            if(check(mid,index,maxSum,n))
            {
                ans=mid;
                start=mid+1;
            }

            else
            {
                end=mid-1;
            }
        }

        return ans;
        
    }
};