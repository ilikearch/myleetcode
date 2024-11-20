class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string> ret;
       for(auto&x:nums){
        ret.push_back(to_string(x));
       }
       sort(ret.begin(),ret.end(),[](const string& s1,const string& s2){
            return s1+s2>s2+s1;
       });
        string st;
        for(auto& e:ret){
            st+=e;
        }
        if(st[0]=='0')return "0";
        return st;
    }
};
