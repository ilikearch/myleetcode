class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        //重写排序 左端点相同右端点大到小 左端点不同右端点小到大
        sort(e.begin(),e.end(),[&](const vector<int>& v1,const vector<int>& v2){
            return v1[0]!=v2[0]?v1[0]<v2[0]:v1[1]>v2[1];
        });
        //最长递增子序列
        vector<int>ret;
        ret.push_back(e[0][1]);
        for(int i=1;i<e.size();i++){
            int b=e[i][1];
            if(b>ret.back())ret.push_back(b);
            else{
                int left=0,right=ret.size()-1;
                while(left<right){
                    int mid=(left+right)/2;
                    if(ret[mid]>=b)right=mid;
                    else left=mid+1;
                }
                ret[left]=b;
            }
        }
        return ret.size();
    }
};
