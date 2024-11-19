class Solution {
public:
    int count=0;
    int ret=0;
    //中序
    int kthSmallest(TreeNode* root, int k) {
        count=k;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root){
        if(root==nullptr||count==0)return;
        dfs(root->left);
        count--;
        if(count==0)ret=root->val;
        dfs(root->right);
    }
};
