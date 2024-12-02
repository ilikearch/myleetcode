class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //正难则反+贪心
        int ret=0;
        while(target>startValue){
            if(target%2==0)target/=2;
            else target+=1;
            ret++;
        }
        return ret+startValue-target;
    }
};
