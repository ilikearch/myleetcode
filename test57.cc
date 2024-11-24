class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //求根数目
        vector<int> ufs(isConnected.size(), -1);
        auto FindRoot = [&ufs](int x) {
            while (ufs[x] >= 0) {
                x = ufs[x];
            }
            return x;
        };
        for (size_t i = 0; i < isConnected.size(); ++i) {
            for (size_t j = 0; j < isConnected[i].size(); ++j) {
                if (isConnected[i][j] == 1) {
                    // 合并集合
                    int root1 = FindRoot(i);
                    int root2 = FindRoot(j);
                    if (root1 != root2) {
                        ufs[root1] += ufs[root2];
                        ufs[root2] = root1;
                    }
                }
            }
        }
        int n=0;
        for(auto e:ufs){
            if(e<0){
                ++n;
            }
        }
        return n;
    }
};
