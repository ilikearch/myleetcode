//1. 先访问左路结点
//2. 再访问左路结点的右⼦树
//从栈中取节点访问右子树
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*cur=root;
        vector<int>v;
        while(cur||!st.empty()){
            //每次循环开始就是访问一棵树（或子树）的开始
            //访问左路节点，左路节点入栈
            while(cur){
                v.push_back(cur->val);
                st.push(cur);
                cur=cur->left;
            }
            //取出一个左路节点的右子树访问
            TreeNode*top=st.top();
            st.pop();

            //循环子问题访问右子树
            cur=top->right;
        }
        return v;
    }
};
