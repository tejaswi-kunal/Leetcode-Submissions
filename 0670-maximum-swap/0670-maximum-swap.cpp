class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);

        // now we have to find the last occurances of each digit 
        vector<int>last_occ(10,-1);

        for(int i=0;i<s.size();i++)
        {
            last_occ[s[i]-'0']=i;
        }

        // now we have to swap the left most number with a digit in right to get a larger number 
        for(int i=0;i<s.size();i++)
        {
            for(int d=9;d>s[i]-'0';d--)
            {
                if(last_occ[d]!=-1 && last_occ[d]>i)
                {
                    swap(s[i],s[last_occ[d]]);
                    int ans=stoi(s);
                    return ans;
                }
            }
        }
        int ans=stoi(s);
        return ans;
        
    }
};