class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int ans=0;

        int n=arr.size();
        // first we have to find the NSL and NSR of the array 
        vector<int>nsl(n);
        vector<int>nsr(n);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                nsr[st.top()]=i;
                st.pop();
            }

            st.push(i);
        } 

        while(!st.empty())
        {
            nsr[st.top()]=n;
            st.pop();
        }

        // now we have to find the nsl
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                nsl[st.top()]=i;
                st.pop();
            }

            st.push(i);
        }
        while(!st.empty())
        {
            nsl[st.top()]=-1;
            st.pop();
        }

        // now we have to find the final ans
        const int m=1e9+7;
        for(int i=0;i<n;i++)
        {
            int l=i-nsl[i]-1;
            int r=nsr[i]-i-1;

            ans=(ans+(1LL*(1LL*l*r+1+l+r)*arr[i])%m)%m;
        }
        
        return ans;
        
    }
};