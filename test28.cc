class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,n=popped.size();
        for(auto& x:pushed){
            st.push(x);
            while(st.size()&&st.top()==popped[i]){
                st.pop();
                i++;
            }
        }
        return i==n;

    }
};
