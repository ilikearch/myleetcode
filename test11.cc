class Solution {
public:
    string countAndSay(int n) {
        string ret = "1"; // 初始化第一个元素
        for(int i = 1; i < n; i++) { // 从 1 循环到 n-1
            string tmp; // 用于构造下一个元素
            int len = ret.size(); // 获取当前元素的长度
            for(int left = 0, right = 0; right < len; ) {
                // 找到连续相同的字符
                while(right < len && ret[left] == ret[right]) right++;
                // 记录相同字符的数量和字符本身
                tmp += to_string(right - left) + ret[left];
                left = right; // 移动 left 到 right
            }
            ret = tmp; // 更新 ret 为新生成的字符串
        }
        return ret; // 返回结果
    }
};

