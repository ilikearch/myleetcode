class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int m=0;
        int n=nums.size();
        int minnum=INT_MAX;
        for(auto  x:nums){
            if(x<0)m++;
            minnum=min(minnum,abs(x));//绝对值最小的数
        }
        int ret=0; 
        if(m>k){
            sort(nums.begin(),nums.end());
            for(int i=0;i<k;i++){
                ret+=-nums[i];
            }
            for(int i=k;i<n;i++){
                ret+=nums[i];
            }
        }else{
            //负数加为正数
            for(int x:nums)ret+=abs(x);
            if((m-k)%2!=0)ret-=minnum*2;
        }
        return ret; 
    }
};
