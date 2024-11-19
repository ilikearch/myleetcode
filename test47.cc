class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode*root,int presum){
        presum=presum*10+root->val;
        if(root->left==nullptr&&root->right==nullptr)return presum;
        int ret=0;
        if(root->left)ret+=dfs(root->left,presum);
        if(root->right)ret+=dfs(root->right,presum);
        return ret;
    }
};
