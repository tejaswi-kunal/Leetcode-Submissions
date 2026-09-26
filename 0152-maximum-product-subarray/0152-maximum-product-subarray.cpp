class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int pos=1,neg=1;
        int ans=-1e9;

        for(auto &it : nums)
        {
            if(it>0)
            {
                pos=max(pos*it,it);
                neg=neg*it;
            }

            else if(it<0)
            {
                int temp=pos;
                pos=neg*it;
                neg=min(temp*it,it);
            }

            else
            {
                pos=0;
                neg=0;
            }

            ans=max(ans,pos);
        }
        
        return ans;
    }
};