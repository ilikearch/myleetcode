class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ret;
        int n=nums.size();
        if(n==1){
            return to_string(nums[0]);
        }
        if(n==2){
            return to_string(nums[0])+"/"+to_string(nums[1]);
        }
        ret=to_string(nums[0])+"/("+to_string(nums[1]);
        for(int i=2;i<n;i++){
            ret+="/"+to_string(nums[i]);
        }
        ret+=")";
        return ret;
    }
};
