class Solution {
public:
    using ll=long long;
    long long subArrayRanges(vector<int>& nums) 
    {
        int n=nums.size();

        // first we have to find the nsl,nsr,ngl,ngr of the given nums
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                int idx=st.top();
                nsr[idx]=i;
                st.pop();

                // now here at the same time we can can give find the nsl of the nums
                if(!st.empty())
                {
                    nsl[idx]=st.top();
                }
            }

            st.push(i);
        }

        // now we have to fill the nsl of the remaining elements 
        while(!st.empty())
        {
            int idx=st.top();
            st.pop();

            if(!st.empty())
            {
                nsl[idx]=st.top();
            }
        }

        // now we have to caculate the min sum 
        ll ans=0,mini=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            int l=i-nsl[i]-1;
            int r=nsr[i]-i-1;
            mini=mini+(1LL*l*r+l+r+1)*nums[i];
        }
        

        // now we have to similarly caculate the maxi
        vector<int>ngr(n,n);
        vector<int>ngl(n,-1);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                int idx=st.top();
                st.pop();

                ngr[idx]=i;
                if(!st.empty())
                {
                    ngl[idx]=st.top();
                }
                
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int idx=st.top();
            st.pop();

            if(!st.empty())
            {
                ngl[idx]=st.top();
            }
        }

        for(int i=0;i<n;i++)
        {
            int l=i-ngl[i]-1;
            int r=ngr[i]-i-1;
            maxi=maxi+(1LL*l*r+l+r+1)*nums[i];
        }

        return maxi-mini;

    }
};