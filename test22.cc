class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        vector<int> ret(n-k+1,-1);
        for(int i=0;i<n;i++){
            cnt=i==0||nums[i]-nums[i-1]!=1?1:cnt+1;
            if(cnt>=k)ret[i-k+1]=nums[i];

        }
        return ret;
    }
};