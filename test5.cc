class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        vector<int> remainder(24, 0); // 存储每个余数的出现次数
        int count = 0;

        for (int h : hours) {
            int rem = h % 24;                 // 当前小时数的余数
            int complement = (24 - rem) % 24; // 需要配对的余数
            count += remainder[complement];   // 统计满足条件的配对数
            remainder[rem]++; // 更新当前余数的出现次数
        }

        return count;
    }
};
