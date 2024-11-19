class Solution {
public:
    vector<string> ret;
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        if(root==nullptr)return ret;
        dfs(root,path);
        return ret;
    }
    //函数参数path便于“恢复现场”
    void dfs(TreeNode*root,string path){
        path+=to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            ret.push_back(path);
            return ;
        }
        path+="->";
        if(root->left)dfs(root->left,path);
        if(root->right)dfs(root->right,path);
    }
};
