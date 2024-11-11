class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto str:tokens){
            if(str!="+"&&str!="-"&&str!="*"&&str!="/"){
                s.push(stoi(str));
            }
            else{
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                switch (str[0]){
                    case '+':
                        s.push(left + right);
                        break;
                    case '-':
                        s.push(left - right);
                        break;
                    case '*':
                        s.push(left * right);
                        break;
                    case '/':
                        s.push(left / right);
                        break;
                    default:
                }
            }
        }
        return s.top();
    }
};
