class Solution {
public:
    string convert(string s, int numRows) {
        // 如果行数为1或字符串长度小于行数，直接返回原字符串
        if (numRows == 1 || numRows >= s.size()) return s;

        string ret;  // 用于存储结果
        int n = s.size();
        int d=2*numRows-2;//间隔
        // 遍历每一行
        for (int i = 0; i < numRows; i++) {
            // 对于第一行和最后一行，直接按照间隔 d取字符
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < n; j += d) {
                    ret += s[j];
                }
            } 
            // 对于中间行，按锯齿形规则取字符
            else {
                for (int j = i, k = d - i; j < n || k < n; j += d, k += d) {
                    if (j < n) ret += s[j];  // 取当前行的字符
                    if (k < n) ret += s[k];  // 取锯齿形上行的字符
                }
            }
        }

        return ret;  // 返回最终结果
    }
};

