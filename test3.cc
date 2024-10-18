class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0; // 记录反转操作的次数

        // 从左到右遍历数组
        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) { // 如果遇到 0
                // 对 i 位置及其后两个元素进行反转
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                ops++; // 增加一次操作计数
            }
        }

        // 检查最后两个元素是否为 1
        if (nums[n - 1] == 0 || nums[n - 2] == 0) {
            return -1; // 如果最后两个元素有 0，无法完成任务
        }

        return ops; // 返回最少的操作次数
    }
};
