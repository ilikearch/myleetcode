class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) {
            return bamboo_len - 1; // 必须拆分，所以 2->1, 3->2
        }
        const int MOD = 1e9 + 7;
        int quotient = bamboo_len / 3;
        int remainder = bamboo_len % 3;
        long long result = 1;
        
        // 计算 3^(quotient - 1) 的情况（余数为1时）
        if (remainder == 1) {
            quotient--;
            remainder = 4;
        }
        
        // 快速幂计算 3^quotient，过程中取模
        for (int i = 0; i < quotient; ++i) {
            result = (result * 3) % MOD;
        }
        
        // 处理余数
        if (remainder != 0) {
            result = (result * remainder) % MOD;
        }
        
        return static_cast<int>(result);
    }
};
