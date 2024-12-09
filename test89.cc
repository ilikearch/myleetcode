// class Solution {
// public:
//     //x在t树中
//     bool Isintree(TreeNode*t,TreeNode*x){
//         if(t==nullptr){
//             return false;
//         }
//         return t==x||Isintree(t->left,x)||Isintree(t->right,x);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==nullptr)return nullptr;
//         if(root==p||root==q)return root;

//         bool pInleft=Isintree(root->left,p);
//         bool pInright=!pInleft;
//         bool qInleft=Isintree(root->left,q);
//         bool qInright=!qInleft;

//         //p q在左递归左子树
//         //p q在右递归右子树
//         //分别在左右 返回
//         if(pInleft&&qInleft)
//         return lowestCommonAncestor(root->left,p,q);
//         else if(pInright&&qInright)
//         return lowestCommonAncestor(root->right,p,q);
//         else return root;
//     }
// };

//前序遍历 利用栈存储路径
class Solution {
public:
    bool Getpath(TreeNode*root,TreeNode*x,stack<TreeNode*>&path){
        //前序
        if(root==nullptr)return false;
        path.push(root);
        if(root==x)return true;
        if(Getpath(root->left,x,path)){
            return true;
        }
        if(Getpath(root->right,x,path)){
            return true;
        }
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ppath,qpath;
        Getpath(root,p,ppath);
        Getpath(root,q,qpath);
        //找交点就是最近公共祖先
        //长的先走
        while(ppath.size()!=qpath.size())
        {
            if(ppath.size()>qpath.size())ppath.pop();
            else qpath.pop();
        }
        //同时
        while(ppath.top()!=qpath.top()){
            ppath.pop();
            qpath.pop();
        }
        return ppath.top();
    }
};
