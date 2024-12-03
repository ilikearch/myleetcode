class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //按左端点排序
        sort(intervals.begin(),intervals.end());
        int left=intervals[0][0],right=intervals[0][1];
        vector<vector<int>> ret;
        for(int i=1;i<intervals.size();i++){
            int a=intervals[i][0],b=intervals[i][1];
            if(a<=right)//有重叠部分
            {
                right=max(b,right);
            }
            else{
                ret.push_back({left,right});
                left=a;
                right=b;
            }
        }
        ret.push_back({left,right});
        return ret;
    }
};
