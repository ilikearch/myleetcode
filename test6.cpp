class Solution {
public:
      int twoEggDrop(int n) {
        int moves = 0; // 记录最小操作次数
        int sum = 0;   // 记录当前能测试的最大楼层数
        // 每增加一次操作 moves，能测试的楼层数会增加 moves 层
        while (sum < n) {
            moves++;
            sum += moves; // 累加可以测试的楼层数
        }
        return moves; // 最终操作次数
    }
};
