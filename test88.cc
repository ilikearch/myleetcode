class Solution {
public:
    string tree2str(TreeNode* root) {
        // 前序遍历
        if (root == nullptr) {
            return "";
        }
        string ret = to_string(root->val);

        // 左右都为空，要省略括号
        // 右为空，要省略括号
        // 左为空，右不为空，不能省略括号

        // 左边和右边有⼀个为空，左边必须有括号
        if(root->left||root->right){
            ret+='(';
            ret+=tree2str(root->left);
            ret+=')';
        }
        //右边空 不需要括号
        if(root->right){
            ret+='(';
            ret+=tree2str(root->right);
            ret+=')';
        }
        return ret;
    }
};
