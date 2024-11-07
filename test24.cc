class Solution {
public:
    string multiply(string n1, string n2) {
        string ret;
        int m=n1.size(),n=n2.size();
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        vector<int> tmp(m+n-1);
        //无进位相乘再相加
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tmp[i+j]+=(n1[i]-'0')*(n2[j]-'0');
            }
        }
        //处理进位
        int cur=0,t=0;
        while(cur<m+n-1||t!=0){
            if(cur<m+n-1)t+=tmp[cur++];
            ret+=t%10+'0';
            t/=10;
        }
        //处理前导零
        while(ret.size()>1&&ret.back()=='0'){
            ret.pop_back();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
