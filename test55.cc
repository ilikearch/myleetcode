class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        for(int i=0,prmin=INT_MAX;i<prices.size();i++){
            ret=max(ret,prices[i]-prmin);
            prmin=min(prmin,prices[i]);
        }
        return ret;
    }
};
