class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";

        queue<TreeNode*> q;
        q.push(root);
        ostringstream result; // 使用ostringstream
        
        result << "[";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result << node->val << ","; // 记录节点值
                q.push(node->left);
                q.push(node->right);
            } else {
                result << "null,";
            }
        }

        string res = result.str();
        // 处理结尾
        if (res.back() == ',') {
            res.back() = ']';
        } else {
            res += ']';
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;

        string content = data.substr(1, data.size() - 2);
        istringstream ss(content);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < tokens.size() && tokens[i] != "null") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            if (i < tokens.size() && tokens[i] != "null") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

