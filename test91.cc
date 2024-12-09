class Solution {
public:
    TreeNode* _buildTree(vector<int> & preorder, vector<int> & inorder,
                         int& prei, int inbegin, int inend) {
        if (inbegin > inend)
            return nullptr;

        // 前序确定根
        TreeNode* root = new TreeNode(preorder[prei++]);

        // 根分割中序左右⼦区间
        int rooti = inbegin;
        while (rooti <= inend) {
            if (inorder[rooti] == root->val)
                break;
            else
                rooti++;
        }

        // 递归左右⼦区间，递归构建左右⼦树
        //  [inbegin, rooti-1] rooti [rooti+1,inend]

        root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int> & preorder, vector<int> & inorder) {
        int i = 0;
        TreeNode* root =
            _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
        return root;
    }
};
