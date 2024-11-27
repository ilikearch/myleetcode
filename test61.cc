class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     //解法一
    //     dfs(nums,0);
    //     return ret;
    // }
    // void dfs(vector<int>& nums,int pos){
    //     if(pos==nums.size()){
    //         ret.push_back(path);
    //         return;
    //     }
    //     //选
    //     path.push_back(nums[pos]);
    //     dfs(nums,pos+1);//下一层
    //     path.pop_back();//恢复现场
    //     //不选
    //     dfs(nums,pos+1);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // 解法二
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>&nums,int pos){
        ret.push_back(path);
        for(int i=pos;i<nums.size();++i){
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();//恢复现场
        }
    }
};
