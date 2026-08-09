class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();

        // first we have to sort the tokens in the inc order
        sort(tokens.begin(),tokens.end());

        int first=0,second=n-1;
        int score=0,ans=0;
        while(first<=second)
        {
            if(power>=tokens[first])
            {
                power-=tokens[first];
                score++;
                ans=max(score,ans);
                first++;
            }

            else if(first!=second && score>0)
            {
                score--;
                power+=tokens[second];
                second--;
            }

            else
            {
                return ans;
            }
        }

        return  ans;
    }
};