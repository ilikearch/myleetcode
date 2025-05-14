class Solution {
public:
//f[i][j] i天j次交易买入状态
//g[i][j] ---------卖出
    const int INF=0x3f3f3f3f;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> f(n,vector<int>(3,-INF));
        auto g=f;
        f[0][0]=-prices[0],g[0][0]=0;
        for(int i=1;i<n;++i){
            for(int j=0;j<3;++j){
                f[i][j]=max(f[i-1][j],g[i-1][j]-prices[i]);
                g[i][j]=g[i-1][j];
                if(j>=1){
                    g[i][j]=max(g[i][j],f[i-1][j-1]+prices[i]);
                }
            }
        }
        int ret=0;
        for(int j=0;j<3;++j){
            ret=max(ret,g[n-1][j]);
        }
        return ret;
    }
};
