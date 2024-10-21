class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        // 对数组进行排序
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // 当前的最小值和最大值
        int current_min = nums[0];
        int current_max = nums[n - 1];
        
        // 初始化最小分数为当前的最大值和最小值的差值
        int min_score = current_max - current_min;
        
        // 遍历数组，尝试将每个元素加 k 或减 k
        for (int i = 0; i < n - 1; ++i) {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            min_score = min(min_score, high - low);
        }
        
        return min_score;
    }
};
