class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        reverse(s.begin(),s.end());

        // now we have to count the number of letters in the last word
        int n=s.size();
        int count=0,i=0;
        while(i<n && s[i]==' ')
        {
            i++;
        }

        while(i<n && s[i]!=' ')
        {
            i++;
            count++;
        }

        return count;
        
    }
};