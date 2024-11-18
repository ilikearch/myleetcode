class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(); // 矩阵的行数
        int n = matrix[0].size(); // 矩阵的列数
        
        // 创建一个 (m+1) x (n+2) 的二维数组 dp，初始化为 INT_MAX
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, INT_MAX));
        
        // 初始化第一行为 0
        for (int i = 0; i <= n+1; ++i) {
            dp[0][i] = 0;
        }
        
        // 动态规划计算最小下降路径和
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i - 1][j - 1];
            }
        }
        
        // 找出最后一行中的最小值作为最终结果
        int ret = dp[m][1];
        for (int i = 2; i <= n; ++i) {
            ret = min(dp[m][i], ret);
        }
        
        return ret;
    }
};
