class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){//依次枚举所有起点
            int rest=0;//标记净收益
            int step=0;
            for(;step<n;++step){//枚举向后走的步数
                int index=(i+step)%n;//走step步之后的下标
                rest=rest+gas[index]-cost[index];
                if(rest<0)break;
            }
            if(rest>=0)return i;
            i=i+step;//优化；
        }
        return -1;
    }
};
