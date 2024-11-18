class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto &e:bills){
            if(e==5){
                five++;
            }
            else if(e==10){
                if(five==0)return false;
                ten++;
                five--;
            }else{
                if(ten&&five){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};
