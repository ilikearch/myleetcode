class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0,right=0,maxpos=0,ret=0,n=nums.size();
        while(left<=right){
            if(maxpos>=n-1){
                return ret;
            }
            for(int i=left;i<=right;i++){
                maxpos=max(maxpos,nums[i]+i);
            }
            left=right+1;
            right=maxpos;
            ret++;
        }
        return -1;
    }
};
