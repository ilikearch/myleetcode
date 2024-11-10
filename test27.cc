class Solution {
public:
    int calculate(string s) {
        vector<int> ret;
        int i = 0, n = s.size();
        char op = '+';
        while (i < n) {
            if (s[i] == ' ')
                i++;
            else if (s[i] >= '0' && s[i] <= '9') {
                int tmp = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                    tmp = tmp * 10 + (s[i++] - '0');
                if (op =='+')
                    ret.push_back(tmp);
                else if (op == '-')
                    ret.push_back(-tmp);
                else if (op =='/')
                    ret.back() /= tmp;
                else
                    ret.back() *= tmp;
                
            } else {
                op = s[i];
                i++;
            }
        }
        int sut = 0;
        for (auto e: ret)
            sut += e;
        return sut;
    }
};
