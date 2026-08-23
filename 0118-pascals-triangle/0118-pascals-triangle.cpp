class Solution {
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>>result;

        vector<int>seq1;
        vector<int>seq2;

        seq1.push_back(1);
        result.push_back(seq1);
        n--;

        while(n)
        {
            seq2.push_back(1);
            for(int i=1;i<seq1.size();i++)
            {
                seq2.push_back(seq1[i]+seq1[i-1]);
            }
            seq2.push_back(1);
            result.push_back(seq2);

            seq1=seq2;
            seq2.clear();
            n--;
        }

        return result;


    }
};