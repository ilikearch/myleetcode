class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*,unsigned int>> q;
       
        q.push_back({root,1});
        unsigned int ret=0;

        while (q.size()) {
            //更新这一层宽度
            auto &[x1,y1]=q[0];
            auto &[x2,y2]=q.back();
            ret=max(ret,y2-y1+1);
            vector<pair<TreeNode*,unsigned int>> tmp;//下层入队
            for (auto[x,y]:q) {
                if(x->left)tmp.push_back({x->left,y*2});
                if(x->right)tmp.push_back({x->right,y*2+1});
            }
            q=tmp;
        }
        return ret;
    }
};
