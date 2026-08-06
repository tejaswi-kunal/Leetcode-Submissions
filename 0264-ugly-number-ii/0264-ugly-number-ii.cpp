class Solution {
public:
    using ll=long long;
    struct Exp
    {
        int a;
        int b;
        int c;
    };

    struct Compare {
        bool operator()(const pair<ll,Exp> &x,
                        const pair<ll,Exp> &y) {
            return x.first > y.first;
        }
    };
    int nthUglyNumber(int n) 
    {
        Exp exp;
        exp.a=0,exp.b=0,exp.c=0;

        priority_queue<pair<ll,Exp>,
               vector<pair<ll,Exp>>,
               Compare> pq;

        unordered_set<ll>s;
        if(n==1)
        {
            return 1;
        }

        int result=1;
        for(int i=n-1;i>0;i--)
        {
            // each time we have three choices
            ll val1=(ll)pow(2,exp.a+1)*pow(3,exp.b)*pow(5,exp.c);
            ll val2=(ll)pow(2,exp.a)*pow(3,exp.b+1)*pow(5,exp.c);
            ll val3=(ll)pow(2,exp.a)*pow(3,exp.b)*pow(5,exp.c+1);

            if(s.count(val1)==0)
            {
                exp.a+=1;
                pq.push({val1,exp});
                s.insert(val1);
                exp.a--;
            }

            if(s.count(val2)==0)
            {
                exp.b++;
                pq.push({val2,exp});
                s.insert(val2);
                exp.b--;
            }

            if(s.count(val3)==0)
            {
                exp.c++;
                pq.push({val3,exp});
                s.insert(val3);
            }
            

            exp=pq.top().second;
            result=pq.top().first;
            pq.pop();
        }

        return result;
        
    }
};