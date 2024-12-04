class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF = 0x3f3f3f3f;
        int sum = 0, x1 = INF, x2 = INF, y1 = INF, y2 = INF;
        // 最小次小
        for (auto x : nums) {
            sum += x;
            if (x % 3 == 1) {
                if (x < x1)
                    x2 = x1, x1 = x;
                else if (x < x2)
                    x2 = x;
            } else if (x % 3 == 2) {
                if (x < y1)
                    y2 = y1, y1 = x;
                else if (x < y2)
                    y2 = x;
            }
        }
        if (sum % 3 == 0)
            return sum;
        else if (sum % 3 == 1)
            return max(sum - x1, sum - y1 - y2);
        else
            return max(sum - y1, sum - x1 - x2);
    }
};

