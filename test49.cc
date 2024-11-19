class Solution {
public:
    //中序
    long prev=LONG_MIN; 
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        bool left=isValidBST(root->left);
        //剪枝
        if(left==false)return false;
        bool cur=false;
        if(root->val>prev)
        cur=true;
        //剪枝
        if(cur==false)return false;
        prev=root->val;
        bool right=isValidBST(root->right);
        return left&&right&&cur;
    }
};
