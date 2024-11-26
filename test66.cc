class Solution {
public:
    int longestPalindrome(string s) {
        int hash[127]{0};
        for(auto ch:s){
            hash[ch]++;
        }
        int ret=0;
        for(int x:hash){
            ret+=x/2*2;
        }
        return ret<s.length()?ret+1:ret;
    }
};
