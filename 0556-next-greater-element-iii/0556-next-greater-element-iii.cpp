class Solution {
public:
    using ll = long long;
    int nextGreaterElement(int n) 
    {
        string s=to_string(n);

        bool x=next_permutation(s.begin(),s.end());
        ll ans=stoll(s);
        if(x && ans<=INT_MAX)
        {
            return ans;
        }
        return -1;
        
    }
};