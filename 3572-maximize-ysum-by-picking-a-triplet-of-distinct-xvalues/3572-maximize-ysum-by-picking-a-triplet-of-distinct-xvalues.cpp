class Solution {
public:
    using pii=pair<int,int>;
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) 
    {
        priority_queue<pii>pq;
        int n=x.size();

        for(int i=0;i<n;i++)
        {
            pq.push({y[i],x[i]});
        }

        int firstx=-1,secondx=-1;
        int firsty,secondy;
        while(!pq.empty())
        {
            auto [it1,it2]=pq.top();
            pq.pop();

            if(firstx==-1 && secondx==-1)
            {
                firstx=it2;
                firsty=it1;
            }

            else if(secondx==-1 && it2!=firstx)
            {
                secondx=it2;
                secondy=it1;
            }

            else
            {
                if(it2!=firstx && it2!=secondx)
                {
                    return firsty+secondy+it1;
                }
            }
        }

        return -1;
        
    }
};