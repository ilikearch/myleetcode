class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        while (cur || !st.empty()) {
            // 访问⼀颗树的开始、左路结点⼊栈
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            // 访问问左路结点和左路结点的右⼦树
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            // 循环⼦问题⽅式访问右⼦树
            cur = top->right;
        }
        return v;
    }
};
