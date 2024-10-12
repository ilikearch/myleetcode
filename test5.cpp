class Solution {
public:
       int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap; // 存储前缀和及其第一次出现的索引
        prefixMap[0] = -1; // 初始化前缀和为0的索引为-1
        int maxLength = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 将0转换为-1
            sum += (nums[i] == 0) ? 1 : -1;

            // 检查当前前缀和是否已经存在
            if (prefixMap.count(sum)) {
                // 计算当前长度
                maxLength = max(maxLength, i - prefixMap[sum]);
            } else {
                // 记录当前前缀和第一次出现的索引
                prefixMap[sum] = i;
            }
        }

        return maxLength; // 返回最长子数组的长度
    }
};
