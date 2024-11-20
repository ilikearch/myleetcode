class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> hp(nums.begin(),nums.end());
        int count=0;
        double sum1=0.0;
        double sum2=0.0;
        for(auto&e:nums){
            sum1+=e;
        }
        while(sum2<sum1/2){
            double x=hp.top()/2;
            sum2+=x;
            hp.pop();
            hp.push(x);
            count++;
        }
        return count;
    }
};
