class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> ufs(26, -1);
        auto FindRoot = [&ufs](int x) {
            while (ufs[x] >= 0) {
                x = ufs[x];
            }
            return x;
        };
        // 先把相等的值加到一个集合中
        for (auto& str : equations) {
            if (str[1] == '=') {
                int root1 = FindRoot(str[0]-'a');
                int root2 = FindRoot(str[3]-'a');
                if (root1 != root2) {
                    ufs[root1] += ufs[root2];
                    ufs[root2] = root1;
                }
            }
        }
        //看不相等的在不在同一集合中在就false
        for(auto&str:equations){
            if(str[1]=='!'){
                int root1 = FindRoot(str[0]-'a');
                int root2 = FindRoot(str[3]-'a');
                if (root1 == root2)return false;
            }
        }
        return true;
    }
};
