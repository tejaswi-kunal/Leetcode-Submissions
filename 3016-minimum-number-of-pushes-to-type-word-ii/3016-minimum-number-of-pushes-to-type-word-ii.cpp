class Solution {
public:
    int minimumPushes(string word) 
    {
        // first we have to caculate the frequency of each character
        vector<int>count(26,0);

        for(int i=0;i<word.size();i++)
        {
            count[word[i]-'a']++;
        }

        // now we have to sort it according to number of there occurances 
        sort(count.rbegin(),count.rend());

        // now we have to calculate the cost 
        int cost=0,times=0,eachCost=1;
        for(int i=0;i<26;i++)
        {
            if(count[i]==0)
            {
                break;
            }

            cost+=eachCost*count[i];
            times++;

            if(times==8)
            {
                times=0;
                eachCost++;
            }
        }

        return cost;
    }
};