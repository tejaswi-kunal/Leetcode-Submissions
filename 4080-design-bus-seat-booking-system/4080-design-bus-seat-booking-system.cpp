class BusBooking {
public:
    vector<vector<int>>seats;
    int totalTime;
    int minTime;

    pair<int,int>row_col(string s)
    {
        pair<int,int>ans;
        ans.second=s[0]-'A'+1;

        // now we have to determine the row 
        string row=s.substr(1,s.size()-1);
        ans.first=stoi(row);

        return ans;
    }

    BusBooking(int n) 
    {
        totalTime=0;
        minTime=0;

        seats.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            seats[i].resize(5);
        }
    }
    
    void toggle(string seat) 
    {
        auto [row, col] = row_col(seat);

        // now we have to allot the seat
        if(!seats[row][col])
        {
            if(col==1)
            {
                if(seats[row][col+1])
                {
                    totalTime+=3;
                    seats[row][col]=3;
                }
                else
                {
                    totalTime+=1;
                    seats[row][col]=1;
                }
            }

            else if(col==4)
            {
                if(seats[row][col-1])
                {
                    totalTime+=3;
                    seats[row][col]=3;
                }

                else
                {
                    totalTime+=1;
                    seats[row][col]=1;
                }
            }

            else
            {
                totalTime+=1;
                seats[row][col]=1;
            }
            minTime+=1;
        }

        else
        {
            totalTime-=seats[row][col];
            minTime--;
            seats[row][col]=0;
        }
    }
    
    int getTotalTime() 
    {
        return totalTime;
    }
    
    int getMinTime() 
    {
        return minTime;   
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */