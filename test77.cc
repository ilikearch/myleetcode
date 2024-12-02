class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int i=0,m=s.size();
        while(i+1<m&&s[i]<=s[i+1])i++;
        if(i+1==m)return n;
        while(i-1>=0&&s[i-1]==s[i])--i;
        s[i]--;
        for(int j=i+1;j<m;j++)s[j]='9';
        return stoi(s);
    }
};
