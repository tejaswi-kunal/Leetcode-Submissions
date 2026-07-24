class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) 
    {
        int n=nums.size();

        int ele_index=max_element(nums.begin(),nums.end())-nums.begin();
        int maxi=nums[ele_index];

        // now we have to find the first number which is power of 2 and greater that maxi
        int max_gcd=1;

        while(max_gcd<=maxi)
        {
            max_gcd*=2;
        }

        // all possible gcds
        vector<int>mp(max_gcd,0);

        // break the solution in two parts
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                int first=nums[j] ^ nums[k];

                if(!mp[first])
                {
                    mp[first]=1;
                }
            }
        }

        // second phase calculation
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mp.size();j++)
            {
                if(mp[j]==1 || mp[j]==3)
                {
                    int second=nums[i] ^ j;

                    if(mp[second]!=2 && mp[second]!=3)
                    {
                        if(mp[second]==1)
                        {
                            mp[second]=3;
                        }

                        else
                        {
                            mp[second]=2;
                        }
                    }
                }
            }
        }

        int count=0;
        for(int i=0;i<mp.size();i++)
        {
            if(mp[i]==2 || mp[i]==3)
            count++;
        }
        
        return count;
    }
};