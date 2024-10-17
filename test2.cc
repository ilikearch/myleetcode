class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];     // 初始化最大和为第一个元素
        int current_sum = nums[0]; // 当前子数组和

        for (int i = 1; i < nums.size(); i++) {
            // 如果当前和加上 nums[i] 小于 nums[i]，则重新开始
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum); // 更新最大和
        }

        return max_sum;
    }
};
