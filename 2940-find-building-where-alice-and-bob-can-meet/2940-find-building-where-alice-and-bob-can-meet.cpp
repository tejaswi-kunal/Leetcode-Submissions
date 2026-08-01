class Solution {
public:
    vector<int>segTree;
    void buildSegTree(int l,int r,int i,vector<int>&nums)
    {
        if(l==r)
        {
            segTree[i]=l;
            return;
        }

        // first build the left and the right subtree
        int mid=l+(r-l)/2;
        buildSegTree(l,mid,2*i+1,nums);
        buildSegTree(mid+1,r,2*i+2,nums);

        if(nums[segTree[2*i+1]]>nums[segTree[2*i+2]])
        {
            segTree[i]=segTree[2*i+1];
        }

        else
        {
            segTree[i]=segTree[2*i+2];
        }
        
    }

    int rimq(int start,int end,int l,int r,int i,vector<int>&nums)
    {
        if(start>end)
        {
            return -1;
        }
        // same as earlier we will have three cases
        // completely outside the range 
        if(r<start || end<l)
        {
            return -1;
        }

        // completely in the range 
        else if(start<=l && r<=end)
        {
            return segTree[i];
        }

        // partially in the range 
        int mid=l+(r-l)/2;

        int idx1 = rimq(start,end,l,mid,2*i+1,nums);
        int idx2 = rimq(start,end,mid+1,r,2*i+2,nums);

        if(idx1==-1)return idx2;
        if(idx2==-1)return idx1;

        if(nums[idx1]>nums[idx2])
        {
            return idx1;
        }

        else
        {
            return idx2;
        }
    }

    int search(vector<int>&nums,int a,int b)
    {
        // we have to find the first element greater than nums[a],nums[b] in (start,end)
        if(a>b)
        {
            swap(a,b);
        }
        if(a==b)
        {
            // they are same index
            return a;
        }

        if(nums[a]<nums[b])
        {
            return b;
        }

        int start=b+1,end=nums.size()-1;


        int n=nums.size();
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            // now find the max element in the left part 
            int idx1=rimq(start,mid,0,n-1,0,nums);

            if(idx1!=-1 && nums[idx1]>nums[a] && nums[idx1]>nums[b])
            {
                // now we can store this one of the possible ans
                ans=idx1;
                end=mid-1;
            }

            else
            {
                int idx2=rimq(mid+1,end,0,n-1,0,nums);

                if(idx2!=-1 && nums[idx2]>nums[a] && nums[idx2]>nums[b])
                {
                    ans=idx2;
                    start=mid+1;
                }

                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {

        // first we have to build the segTree
        int n=heights.size();
        segTree.resize(4*n);
        buildSegTree(0,n-1,0,heights);
        
        vector<int>ans;
        for(auto &it : queries)
        {
            ans.push_back(search(heights,it[0],it[1]));
        }

        return ans;
    }
};