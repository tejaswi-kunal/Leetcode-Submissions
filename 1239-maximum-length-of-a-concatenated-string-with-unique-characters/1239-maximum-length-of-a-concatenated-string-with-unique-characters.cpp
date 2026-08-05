class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        int n=arr.size();
        vector<bool>mp(26,0);

        return solve(n-1,mp,arr);
        
    }

    bool check(vector<bool>mp,string str)
    {
        // we have to check if each character of str has not arrived yet 
        for(auto &it : str)
        {
            if(mp[it-'a'])
            {
                return false;
            }
            mp[it-'a']=1;
        }

        return true;
    }

    int solve(int i,vector<bool>&mp,vector<string>&arr)
    {
        if(i<0)
        {
            return 0;
        }


        // now we have two choices for each string 
        // take or notTake

        bool flag=check(mp,arr[i]);

        int c1=-1,c2=-1;
        if(flag)
        {
            for(auto &it : arr[i])
            {
                mp[it-'a']=1;
            }

            c1=arr[i].size()+solve(i-1,mp,arr);

            // now we have to undo the mp before not take
            for(auto &it : arr[i])
            {
                mp[it-'a']=0;
            }
        }

        // second choice would be to not take
        c2=solve(i-1,mp,arr);

        return max(c1,c2);
    }
};