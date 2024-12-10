class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> v;
        TreeNode* prev = nullptr;
        while (cur || !s.empty()) {
            // 访问⼀颗树的开始、左路结点⼊栈
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode* top = s.top();
            // top结点的右为空或者上⼀个访问结点等于他的右孩⼦
            // 那么说明(空) 不⽤访问或者(不为空) 右⼦树已经访问过了
            // 那么说明当前结点左右⼦树都访问过了，可以访问当前结点
            if (top->right == nullptr || top->right == prev) {
                s.pop();
                v.push_back(top->val);
                prev = top;
            } else {
                // 右⼦树不为空，且没有访问，循环⼦问题⽅式右⼦树
                cur = top->right;
            }
        }
        return v;
    }
};
