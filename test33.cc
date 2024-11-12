class Solution {
public:
    struct cmp {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;

        } // 字典序大根堆            //频次小根堆
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        //统计频次
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            cnt[word]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> heap;
        for(auto& p:cnt){
            heap.push(p);
            if(heap.size()>k)heap.pop();
        }
        //提取结果
        vector<string> ret(k);
        for(int i=k-1;i>=0;i--){
            ret[i]=heap.top().first;
            heap.pop();
        }
        return ret;
    }
};
