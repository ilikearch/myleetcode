class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            if(nums[i]>0)break;
            int left=i+1;
            int right=n-1;
            int target=-nums[i];
            while(left<right){
                if(nums[left]+nums[right]<target)left++;
                else if(nums[left]+nums[right]>target)right--;
                else{
                    ret.push_back({nums[i],nums[left++],nums[right--]});
                    while(left<right&&nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right+1]){
                        right--;
                    }
                } 
            }
            i++;
            while(i<n&&nums[i]==nums[i-1])i++;
        }
        return ret;
    }
};

