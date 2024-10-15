class Solution {
public:
    bool canArriveOnTime(int speed, vector<int>& dist, double hour) {
        double totalTime = 0.0;
        int n = dist.size();

        for (int i = 0; i < n; ++i) {
            totalTime += (double)dist[i] / speed;
            // 不是最后一班车，要向上取整等待整点
            if (i < n - 1) {
                totalTime = ceil(totalTime);
            }
        }

        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canArriveOnTime(mid, dist, hour)) {
                result = mid;  // 记录当前的速度
                right = mid - 1;  // 尝试更小的速度
            } else {
                left = mid + 1;  // 增加速度
            }
        }

        return result;
    }
};

