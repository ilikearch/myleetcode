class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left=0,right=s.size();
        vector<int> ret;
        for(auto x:s){
            if(x=='I')ret.push_back(left++);
            else  ret.push_back(right--);
        }
        ret.push_back(left);

        return ret;
    }
};
