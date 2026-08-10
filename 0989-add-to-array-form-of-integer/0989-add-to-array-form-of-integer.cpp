class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) 
    {
        int n=nums.size();
        reverse(nums.begin(),nums.end());

        // now we have to add the integer k
        int i=0,carry=0;
        while(k && i<nums.size())
        {
            int rem=k%10;
            rem+=carry;
            k/=10;

            nums[i]+=rem;
            if(nums[i]>=10)
            {
                carry=nums[i]/10;
                nums[i]=nums[i]%10; 
            }
            else
            {
                carry=0;
            }
            i++;
        }

        while(k)
        {
            int rem=k%10;
            rem+=carry;
            k/=10;

            if(rem>=10)
            {
                carry=rem/10;
                rem%=10;
            }

            else
            {
                carry=0;
            }
            nums.push_back(rem);
        }

        while(carry && i<n)
        {
            nums[i]+=carry;

            if(nums[i]>=10)
            {
                carry=nums[i]/10;
                nums[i]=nums[i]%10;
            }
            else
            {
                carry=0;
            }
            i++;
        }

        if(carry)
        {
            nums.push_back(carry);
        }

        reverse(nums.begin(),nums.end());

        return nums;
        
    }
};