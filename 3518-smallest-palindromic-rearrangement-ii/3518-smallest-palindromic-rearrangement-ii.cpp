class Solution {
public:

    using ll = long long;
    ll nCr(int n,int r,int k)
    {
        ll result=1;
        r=min(r,n-r);
        for(int i=1;i<=r;i++)
        {
            result=result*(n-r+i)/i;

            if(result>=k)
            {
                return k;
            }
        }

        return result;
    }


    ll Ways(int letters,vector<int>&count,int k)
    {
        ll result=1;
        for(int i=0;i<26;i++)
        {
            if(count[i])
            result*=nCr(letters,count[i],k);

            letters-=count[i];

            if(result>=k)
            {
                // breaking loop early will give us edge in cp
                return k;
            }
        }

        return result;
    }

    string smallestPalindrome(string s, int k) 
    {
        // first we have to calculate the mid and count of half of the characters
        int n=s.size();

        char mid;
        if(n%2!=0)
        mid=s[n/2];

        vector<int>count(26,0);
        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
        }

        if(n%2!=0)
        {
            count[mid-'a']--;
        }

        // now we have to half the total count
        for(int i=0;i<26;i++)
        {
            count[i]/=2;
        }

        int halfSize=n/2;
        if(Ways(halfSize,count,k) < k)
        return "";

        // now we have to calculate the kth lexographical permutation of the given string
        
        string half;
        for(int i=0;i<halfSize;i++)
        {
            for(int j=0;j<26;j++)
            {
                int ways=0;
                if(count[j]>0)
                {
                    // we try out all the characters ,only if its present 
                    count[j]--;

                    // what are the number of permutations possible ,if we fix this character
                    ways=Ways(halfSize-i-1,count,k);
                

                    if(ways>=k)
                    {
                        // now fix the next pos
                        half.push_back(j+'a');
                        break;
                    }

                    // ways<k
                    k-=ways;
                    count[j]++;
                    // now try to fix next character at this pos

                }
            }
        }

        string ans="";

        string secondHalf=half;
        reverse(secondHalf.begin(),secondHalf.end());
        
        ans=half;

        if(n&1)
        {
            ans.push_back(mid);
        }
        ans+=secondHalf;
        return ans;
    }
};