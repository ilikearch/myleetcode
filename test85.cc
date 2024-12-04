class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        unordered_map<int,int> hash;//统计每个数频次
        int maxVal=0,maxCount=0;
        for(auto x : b){
            if(maxCount<++hash[x]){
                maxCount=hash[x];
                maxVal=x;
            }
        }
        int n=b.size();
        vector<int>ret(n);
        int index=0;
        //先处理次数最多的数字
        for(int i=0;i<maxCount;i++){
            ret[index]=maxVal;
            index+=2;
        }
        hash.erase(maxVal);
        //剩下的数
        for(auto&[x,y]:hash){
            for(int i=0;i<y;i++){
                if(index>=n)index=1;
                ret[index]=x;
                index+=2;
            }
        }
        return ret;
    }
};
