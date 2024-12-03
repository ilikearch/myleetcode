class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int right = points[0][1];
        int ret = 1;
        for (int i = 1; i < points.size(); i++) {
            int a = points[i][0], b = points[i][1];
            if (a <= right) // 有重叠部分
            {
                
                right = min(b, right); // 贪心留小区间
            } else {
                ret++;
                right = b;
            }
        }
        return ret;
    }
};
