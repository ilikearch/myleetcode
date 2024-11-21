class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int left = 0, right = 0;
        int ret = 0;
        int n=nums.size();
        for (int i = 0; i < n - 1; ++i) {
            right = nums[i + 1] - nums[i];
            if (right == 0)
                continue;
            if (left * right <= 0) {
                ret++;
                left = right;
            }
        }
        return ret + 1;
    }
};
