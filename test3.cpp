class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> countmap;
        for(auto num:nums2){
            countmap[num]++;
        }
        int count=0;
        for(auto num:nums1){
            for(const auto& pair:countmap){
                int nums=pair.first;
                int mul=nums*k;
                if(mul!=0&&num%mul==0){
                    count+=pair.second;
                }
            }
        }
        return count;
    }
};
