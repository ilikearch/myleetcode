class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 1LL * *max_element(time.begin(), time.end()) * totalTrips;//1LL是一种强制将数值转换为 long long 类型的方式,LL 是 long long 类型的后缀.
//max_element返回最大元素的迭代器

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long trips = 0;

            for (int t : time) {
                trips += mid / t;
            }

            if (trips < totalTrips) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

