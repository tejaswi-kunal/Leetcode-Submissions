class Solution {
public:

    bool check(int mid,vector<int>&price,int k)
    {
        // now we have to check if we can take k items if the min abs diff bw items is allowed as mid;
        int count=1,prev=price[0];
        for(int i=1;i<price.size();i++)
        {
            if(price[i]-prev>=mid)
            {
                count++;
                prev=price[i];
            }
        }

        if(count>=k)
        {
            return 1;
        }

        return 0;
    }

    int maximumTastiness(vector<int>& price, int k) 
    {
        sort(price.begin(),price.end());

        // now we have to maximize the min abs diff bw two prices 
        int start=1,end=price[price.size()-1]-price[0];
        int ans=0;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(check(mid,price,k))
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