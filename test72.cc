class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=s.size(),m=g.size();
        int ret=0;
        for(int i=0,j=0;i<m&&j<n;++i,++j){
            while(j<n&&s[j]<g[i])j++;
            if(j<n)ret++;
        }
        return ret;
    }
};
