class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0], right = intervals[0][1];
        int ret=0;
        for (int i = 1; i < intervals.size(); i++) {
            int a = intervals[i][0], b = intervals[i][1];
            if (a < right) // 有重叠部分
            {
                ret++;
                right = min(b, right);//贪心留小区间
            } else {
                right = b;
            }
        }
        return ret;
    }
};
