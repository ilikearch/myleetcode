class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if(root==nullptr)return ret;
        q.push(root);
        int level=1;

        while (q.size()) {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; ++i) {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            if(level%2==0){
                reverse(tmp.begin(),tmp.end());
            }
            level++;
            ret.push_back(tmp);
        }
        return ret;
    }
};
