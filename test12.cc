class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string t = "croak";
        int n = t.size();
        vector<int> hash(n, 0); // 初始化状态数组

        unordered_map<char, int> index;
        for (int i = 0; i < n; i++) {
            index[t[i]] = i; // 字符到索引的映射
        }

        for (auto ch : croakOfFrogs) {
            if (ch == 'c') {
                if (hash[n - 1] != 0) hash[n - 1]--; // 如果有已完成的 'k'
                hash[0]++; // 开始新的 'croak'
            } else {
                int i = index[ch];
                if (hash[i - 1] == 0) return -1; // 前一个字符必须存在
                hash[i - 1]--; // 减少前一个字符的数量
                hash[i]++; // 增加当前字符的数量
            }
        }

        // 检查是否有未完成的字符
        for (int i = 0; i < n - 1; i++) {
            if (hash[i] != 0) {
                return -1; // 有未完成的字符
            }
        }

        return hash[n - 1]; // 返回需要的青蛙数量
    }
};
