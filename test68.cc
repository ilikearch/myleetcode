class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        vector<int> index2(n);//下标数组
        for(int i=0;i<n;i++)index2[i]=i;
        sort(index2.begin(),index2.end(),[&nums2](int i,int j){
            return nums2[i]<nums2[j];
        });
        //田忌赛马
        vector<int> ret(n);
        int left=0,right=n-1;
        for(auto x:nums1){
            if(x>nums2[index2[left]]) ret[index2[left++]]=x;
            else ret[index2[right--]]=x;
        }
        return ret;
    }
};
