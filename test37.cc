class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n=A.size();
        dfs(A,B,C,n);
    }
    void dfs(vector<int> &a,vector<int> &b,vector<int> &c,int n){
        if(n==1){
            c.push_back(a.back());
            a.pop_back();
            return;
        }

        dfs(a,c,b,n-1);
        c.push_back(a.back());
        a.pop_back();
        dfs(b,a,c,n-1);;
    }
};