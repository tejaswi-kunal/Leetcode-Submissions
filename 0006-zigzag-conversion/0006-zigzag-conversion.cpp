class Solution {
public:
    string convert(string s, int num) 
    {
        if(num==1)
        {
            return s;
        }
        vector<string>ans(num);
        int i=0,n=s.size(),j=0;

        while(i<n)
        {
            while(i<n && j<num)
            {
                ans[j].push_back(s[i]);
                i++,j++;
            }

            j=num-2;
            while(i<n && j>0)
            {
                ans[j].push_back(s[i]);
                i++,j--;
            }
        }

        // now we have to collab the ans 
        string final_ans;

        for(int i=0;i<ans.size();i++)
        {
            final_ans+=ans[i];
        }

        return final_ans;
        
    }
};