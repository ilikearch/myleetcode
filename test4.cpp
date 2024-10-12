class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int ,int> count;
        for(auto &num:nums){
            count[num]++;
        }
        int ans=0;
        for(auto &num:count){
            if(num.second==2){
                ans^=num.first;
            }
        }
        return ans;
    }
};
