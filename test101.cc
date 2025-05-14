class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N=10001;
        //预处理
        int arr[N]={0};
        for(auto a:nums)arr[a]+=a;
        //打家劫舍
        vector<int> f(N);
        auto g=f;
        for(int i=1;i<N;++i){
            f[i]=g[i-1]+arr[i];
            g[i]=max(g[i-1],f[i-1]);

        }
        return max(f[N-1],g[N-1]);
    }
};
