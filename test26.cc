class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return stringCompare(s) == stringCompare(t);
    }

    string stringCompare(string s) {
        string ret;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if(s[i]!='#')ret+=s[i];
            else{
                if(ret.size())ret.pop_back();
            }
            i++;
        }
        return ret;
    }
};

