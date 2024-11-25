class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if(root==nullptr)return ret;
        q.push(root);

        while (q.size()) {
            int sz = q.size();
            int tmp=INT_MIN;
            for (int i = 0; i < sz; ++i) {
                auto front = q.front();
                q.pop();
                tmp=max(front->val,tmp);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
