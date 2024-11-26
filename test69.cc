class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // 创建一个包含名字和身高的 pair 数组
        vector<pair<int, string>> nh;
        for (int i = 0; i < names.size(); ++i) {
            nh.push_back({heights[i], names[i]});
        }
        
        // 按照身高（第一个元素）从低到高排序
        sort(nh.begin(), nh.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;  // 从低到高排序
        });
        
        // 提取排序后的名字
        vector<string> result;
        for (const auto& p : nh) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<int> index(n);//下标数组
        for(int i=0;i<n;i++){
            index[i]=i;
        }
        //以身高为标准对下标排序
        sort(index.begin(),index.end(),[&heights](int i,int j){
            return heights[i]>heights[j];
        });
        //提取结果
        vector<string> ret;
        for(int i:index){
            ret.push_back(names[i]);
        }
        return ret;
    }
};
