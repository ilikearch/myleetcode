class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    left=mid+1;
                }else{
                    right=mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    left=mid+1;
                }else{
                    right=mid;
                }
            }
        }
        return nums[left];
    }
};
