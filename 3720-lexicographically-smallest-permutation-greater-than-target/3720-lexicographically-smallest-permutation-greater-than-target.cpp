class Solution {
public:
    string lexGreaterPermutation(string s, string target) 
    {
        int n=s.size();
        string ans;

        // first we have to count the freq of each character 
        vector<int>mp(26,0);

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }

        // now we have to construct the ans
        string temp;
        solve(target,ans,temp,mp,false,0);

        return ans;
        
    }

    void solve(string &t,string &ans,string &temp,vector<int>&mp,bool found,int i)
    {

        if(found)
        {
            // now we have to fill the rest of the letters in the sorted manner 
            for(int j=0;j<26;j++)
            {
                while(mp[j])
                {
                    temp.push_back(j+'a');
                    mp[j]--;
                }
            }
            ans=temp;
            return;
        }

        if(i==t.size())
        {
            if(found)
            {
                ans=temp;
            }
            return;
        }

        for(int j=t[i]-'a';j<26;j++)
        {
            if(mp[j])
            {
                temp.push_back(j+'a');
                mp[j]--;

                if(t[i]<j+'a')
                {
                    found=1;
                }

                solve(t,ans,temp,mp,found,i+1);

                temp.pop_back();
                mp[j]++;
            }
            // we dont have to explore further
            if(ans.size()!=0)
            {
                return;
            }
        }
    }
};