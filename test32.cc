class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        q.push(root);
        if(root==nullptr){
            return vv;
        }
        int levelsize=1;
        while(!q.empty()){
            vector<int> v;
            while(levelsize--){
                auto node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right); 
            }
            vv.push_back(v);
            levelsize=q.size();
        }
        return vv;
    }
};
