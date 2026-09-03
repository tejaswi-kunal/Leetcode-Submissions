class Solution {
public:
    int maxValidSplits(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=-1;i<n;i++)
        {
            // build the rem array 
            vector<int>arr;
            
            for(int j=0;j<n;j++)
            {
                if(j==i)
                {
                    continue;
                }

                else
                {
                    arr.push_back(nums[j]);
                }
            }
            ans=max(ans,solve(arr));
        }
        
        return ans;
    }

    int solve(vector<int>&arr)
    {
        // first we have to form the pgcd and sgcd
        int n=arr.size();
        vector<int>pgcd(n);
        vector<int>sgcd(n);
        
        pgcd[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            pgcd[i]=gcd(pgcd[i-1],arr[i]);
        }

        sgcd[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sgcd[i]=gcd(sgcd[i+1],arr[i]);
        }

        // now we have to find the number of points pgcd i == sgcd i+1;
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(pgcd[i]==sgcd[i+1])
            {
                count++;
            }
        } 

        return count;
    }
};