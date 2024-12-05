class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        map<string,function<int(int,int)>> opFunmap={
            {"+",[](int x,int y){return x+y;}},
            {"-",[](int x,int y){return x-y;}},
            {"*",[](int x,int y){return x*y;}},
            {"/",[](int x,int y){return x/y;}}
        };
        for(auto& str:tokens){
            if(str!="+"&&str!="-"&&str!="*"&&str!="/"){
                s.push(stoi(str));
            }
            else{
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                int ret=opFunmap[str](left,right);
                s.push(ret);
            }
        }
        return s.top();
    }
};
