class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) 
    {
        int op=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    if(locked[j])
                    {
                        if(k)
                        {
                            locked[j]=0;
                            k--;
                            op++;
                        }

                        else
                        return -1;
                    }

                    if(locked[j+1])
                    {
                        if(k)
                        {
                            locked[j+1]=0;
                            k--;
                            op++;
                        }
                        else
                        return -1;
                    }

                    swap(nums[j],nums[j+1]);
                    op++;
                }
            }
        }

        return op;
        
    }
};