class Solution {
public:
    using ll=long long;
    int nthUglyNumber(int n) 
    {
        if(n==1)
        {
            return 1;
        }

        priority_queue<ll,vector<ll>,greater<ll>>pq;
        unordered_set<ll>s;

        ll result=1;
        for(int i=n-1;i>0;i--)
        {
            // each time we have three choices
            ll val1=result*2;
            ll val2=result*3;
            ll val3=result*5;

            if(s.count(val1)==0)
            {
                pq.push(val1);
                s.insert(val1);
            }

            if(s.count(val2)==0)
            {
                pq.push(val2);
                s.insert(val2);
            }

            if(s.count(val3)==0)
            {
                pq.push(val3);
                s.insert(val3);
            }
            
            result=pq.top();
            pq.pop();
        }
        return result;
        
    }
};