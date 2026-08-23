class Solution {
public:
    bool case1(int l,int k,int s1,int s2)
    {
        // max sum ranges alice can get
        int r11=s1;
        int r12=s1+((k+1)/2)*9;

        int r21=s2;
        int r22=s2+(l/2)*9;

        // now we have to check if bob can reach all ranges 
        bool check1=0,check2=0;
        if(r22<=r11+(k/2)*9)
        {
            check1=1;
        }

        if(r12<=r21+((l+1)/2)*9)
        {
            check2=1;
        }

        return check1 && check2;
    }

    bool case2(int l,int k,int s1,int s2)
    {
        int r11=s1;
        int r12=s1+(k/2)*9;

        int r21=s2;
        int r22=s2+((l+1)/2)*9;

        // now we have to check if bob can reach all ranges 
        bool check1=0,check2=0;
        if(r22<=r11+((k+1)/2)*9)
        {
            check1=1;
        }

        if(r12<=r21+(l/2)*9)
        {
            check2=1;
        }

        return check1 && check2;
    }
    bool sumGame(string nums) 
    {
        int n=nums.size();
        
        int s1=0,s2=0,k=0,l=0;

        for(int i=0;i<n/2;i++)
        {
            if(nums[i]!='?')
            s1+=(nums[i]-'0');

            else
            k++;
        }

        for(int i=n/2;i<n;i++)
        {
            if(nums[i]!='?')
            s2+=(nums[i]-'0');

            else
            l++;
        }

        // now we have to find the max range to r1 and r2
        if(l>0 && k>0)
        return !(case1(l,k,s1,s2) && case2(l,k,s1,s2));

        else if(k>0)
        return !case1(l,k,s1,s2);

        else
        return !case2(l,k,s1,s2);
    }
};