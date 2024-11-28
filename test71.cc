class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return qsort(nums,0,nums.size()-1,k);
    }
    //快速选择
    int qsort(vector<int>&nums,int l,int r,int k){
        if(l==r)return nums[l];
        int key=getRandom(nums,l,r);
        int i=l,left=l-1,right=r+1;
        //数组分三段
        while(i<right){
            if(nums[i]<key)swap(nums[++left],nums[i++]);
            else if(nums[i]==key)i++;
            else swap(nums[--right],nums[i]);
        }
        //[l,left][left+1,right-1][right,r];
        int c=r-right+1,b=right-1-left-1+1;
        if(c>=k)return qsort(nums,right,r,k);
        else if(b+c>=k)return key;
        else return qsort(nums,l,left,k-b-c);
    }
    int getRandom(vector<int>&nums,int left,int right){
        int r=rand();
        return nums[r%(right-left+1)+left];
    }
};
