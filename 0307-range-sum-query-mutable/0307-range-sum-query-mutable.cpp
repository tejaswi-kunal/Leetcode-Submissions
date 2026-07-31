class NumArray {
public:
    vector<int>segTree;
    int n;
    NumArray(vector<int>& nums) {
        segTree.resize(4*nums.size());
        n=nums.size();

        // now we have to build the segTree
        Build(0,nums.size()-1,0,nums,segTree);
    }

    void Build(int l,int r,int i,vector<int>&nums,vector<int>&segTree)
    {
        if(l==r)
        {
            segTree[i]=nums[l];
            return;
        }

        int mid=l+(r-l)/2;

        // now we have to build its left and the right subtree
        Build(l,mid,2*i+1,nums,segTree);
        Build(mid+1,r,2*i+2,nums,segTree);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    
    void update(int index, int val) 
    {
        // here we have to update the segTree the value of the nums[index] is changed to the newVal 
        updateSegTree(0,n-1,0,index,val,segTree);
        
    }

    void updateSegTree(int l,int r,int i,int index,int val,vector<int>&segTree)
    {
        if(l==r)
        {
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;

        // first update the left or right subtree
        if(index<=mid)
        {
            updateSegTree(l,mid,2*i+1,index,val,segTree);
        }

        else 
        {
            updateSegTree(mid+1,r,2*i+2,index,val,segTree);
        }

        // now update this index according to the updated left and right subtree
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    
    int sumRange(int left, int right) 
    {
        // now we have to use the seg tree we built to answeer the query 
        return Query(0,n-1,0,left,right,segTree);    
    }

    int Query(int l,int r,int i,int start,int end,vector<int>&segTree)
    {
        // we have three conditions for each node 
        // completely outside the range 
        if(r<start || end<l)
        {
            return 0;
        }

        // coompletely inside the range 
        else if(start<=l && r<=end)
        {
            return segTree[i];
        }

        // paritiallt in the range 
        int mid=l+(r-l)/2;

        return Query(l,mid,2*i+1,start,end,segTree)+Query(mid+1,r,2*i+2,start,end,segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */