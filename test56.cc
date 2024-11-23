class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //双指针
        /*int ret=0,n=prices.size();
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&prices[j]>prices[j-1])j++;
            ret+=prices[j-1]-prices[i];
            i=j;
        }
        return ret;*/
        //拆分成一天一天
        int ret=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1])ret+=prices[i]-prices[i-1];
        }
        return ret;
    }
};
