// sort pair increasing (first -> second)
static bool comp(pair<int,int>& a, pair<int,int>& b)
{
    return a.first<b.first;
}

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) 
    {
        // first we have to sort the robots and walls on the basis of their position
        vector<pair<int,int>>robotDis(robots.size());
        for(int i=0;i<robots.size();i++)
        {
            robotDis[i]={robots[i],distance[i]};
        }

        sort(walls.begin(),walls.end());
        sort(robotDis.begin(),robotDis.end(),comp);

        // first we have to find the range of each robot 
        vector<pair<int,int>>range(robots.size());

        // first robot left side
        range[0].first=robotDis[0].first-robotDis[0].second;

        // last robot right side
        range[robots.size()-1].second=robotDis[robots.size()-1].first+robotDis[robots.size()-1].second;
        for(int i=0;i<robots.size();i++)
        {
            // leftSide
            if(i)
            range[i].first=max(robotDis[i-1].first+1,robotDis[i].first-robotDis[i].second);

            // rightSide
            if(i!=robots.size()-1)
            range[i].second=min(robotDis[i+1].first-1,robotDis[i].first+robotDis[i].second);
        }

        // now we have to apply all the combinations
        vector<vector<int>>dp(robots.size(),vector<int>(2,-1));

        return solve(robots.size()-1,1,robotDis,walls,dp,range);
    }


    int solve(int i,int dir,vector<pair<int,int>>&robotDis,vector<int>&walls,vector<vector<int>>&dp,vector<pair<int,int>>&range)
    {
        if(i==-1)
        {
            return 0;
        }

        if(dp[i][dir]!=-1)
        {
            return dp[i][dir];
        }
        // each robot has two choices ->either fire the bullet in the left direction or in the right direction
        int c1=0,c2=0;

        // leftside
        // leftRange-----robotPos

        // w>=leftRange
        int index1=lower_bound(walls.begin(),walls.end(),range[i].first)-walls.begin();
        if(index1==walls.size())
        {
            index1=-1;
        }

        // w<=robotpos
        int index2=upper_bound(walls.begin(),walls.end(),robotDis[i].first)-walls.begin()-1;
    
        if(index1!=-1 && index2!=-1 && index1<=index2)
        {
            c1=index2-index1+1;
        }
        c1+=solve(i-1,0,robotDis,walls,dp,range);

        // rightSide
        // robotPos----rightRange
        int rightRange=range[i].second;
        if(dir==0)
        {
            rightRange=min(range[i].second,range[i+1].first-1);
        }

        //w>=robotPos
        int index3=lower_bound(walls.begin(),walls.end(),robotDis[i].first)-walls.begin();
        if(index3==walls.size())
        {
            index3=-1;
        }

        // w<=rightRange
        int index4=upper_bound(walls.begin(),walls.end(),rightRange)-walls.begin()-1;

        if(index3!=-1 && index4!=-1 && index3<=index4)
        {
            c2=index4-index3+1;
        }
        c2+=solve(i-1,1,robotDis,walls,dp,range);

        return dp[i][dir]=max(c1,c2);  
    }
};