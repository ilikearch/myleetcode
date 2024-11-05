class Solution {
public:
    string losingPlayer(int x, int y) {
        int count = 0;
        
        // 计算可以进行的最大操作次数
        while (x >= 1 && y >= 4) {
            x--;  // 拿出 1 个 75 的硬币
            y -= 4;  // 拿出 4 个 10 的硬币
            count++;  // 增加操作次数
        }
        
        // 如果 count 为 0，表示 Alice 无法进行任何操作，Alice 输
        if (count == 0) {
            return "Bob";
        }
        
        // 根据操作次数的奇偶性判断输的人
        return count % 2 == 1 ? "Alice" : "Bob";
    }
};

