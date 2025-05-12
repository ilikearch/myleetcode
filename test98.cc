class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0; // 没有房屋，返回0
        if (n == 1)
            return nums[0]; // 只有一间房屋，返回它的金额
        if (n == 2)
            return max(nums[0], nums[1]);
        // 选择偷第一个房屋（加上从2到n-2的最大值）或偷第二到最后一间房屋的最大值
        return max(_rob(nums, 2, n - 2) + nums[0], _rob(nums, 1, n - 1));
    }

    int _rob(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> f(n);       // f[i] 表示到达 i 时偷到的最大金额
        vector<int> g(n);       // g[i] 表示不偷 i 时的最大金额
        f[start] = nums[start]; // 如果偷了 start 房屋
        g[start] = 0;           // 不偷 start 房屋的最大金额为0

        // 从 start + 1 房屋开始取值，直到 end
        for (int i = start + 1; i <= end; i++) {
            f[i] = g[i - 1] + nums[i];      // 偷 i 房屋
            g[i] = max(f[i - 1], g[i - 1]); // 不偷 i 房屋
        }

        return max(f[end], g[end]); // 返回到达 end 时的最大金额
    }
};



