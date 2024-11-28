class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(NULL));
        qsort(stock,0,stock.size()-1,cnt);
        return {stock.begin(),stock.begin()+cnt};
    }
    //快速选择
    void qsort(vector<int>&nums,int l,int r,int k){
        if(l>=r)return;
        int key=getRandom(nums,l,r);
        int i=l,left=l-1,right=r+1;
        //数组分三段
        while(i<right){
            if(nums[i]<key)swap(nums[++left],nums[i++]);
            else if(nums[i]==key)i++;
            else swap(nums[--right],nums[i]);
        }
        //[l,left][left+1,right-1][right,r];
        int c=left-l+1,b=right-1-left-1+1;
        if(c>k) qsort(nums,l,left,k);
        else if(b+c>=k)return ;
        else  qsort(nums,right,r,k-b-c);
    }
    int getRandom(vector<int>&nums,int left,int right){
        int r=rand();
        return nums[r%(right-left+1)+left];
    }
};
