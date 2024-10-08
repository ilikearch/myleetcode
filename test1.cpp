class Solution {
public:
    int takeCharacters(string s, int k) {
         unordered_map<char, int> totalCount;
        for (char ch : s) {
            totalCount[ch]++;
        }

        // 验证是否有字符数量小于 k，如果有则返回 -1
        for (char key : {'a', 'b', 'c'}) {
            if (totalCount[key] < k) {
                return -1;
            }
            // 减去 k，用于后续计算
            else {
                totalCount[key] -= k;
            }
        }

        unordered_map<char, int> windowCount;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            windowCount[s[right]]++;

            // 如果当前窗口内的字符数量超过了允许的最大值，则移动左边界
            while (right >= left && (windowCount['a'] > totalCount['a'] ||
                                     windowCount['b'] > totalCount['b'] ||
                                     windowCount['c'] > totalCount['c'])) {
                windowCount[s[left]]--;
                left++;
            }

            // 更新最大子串长度
            maxLen = max(maxLen, right - left + 1);
        }

        // 返回从左侧和右侧取字符的次数
        return s.size() - maxLen;
    }
};
