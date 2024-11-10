class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<int> nums;
        stack<string> st;
        st.push("");
        int i=0;
        while(i<n){
            if(s[i]>='0'&&s[i]<='9'){
                int tmp=0;
                while(s[i]>='0'&&s[i]<='9'){
                    tmp=tmp*10+(s[i]-'0');
                    i++;
                }
                nums.push(tmp);
            }
            else if(s[i]=='['){
                i++;
                string tmp;
                while(s[i]>='a'&&s[i]<='z'){
                    tmp+=s[i];
                    i++;
                }
                st.push(tmp);
            }
            else if(s[i]==']'){
                string tmp=st.top();
                st.pop();
                int k=nums.top();
                nums.pop();
                while(k--){
                    st.top()+=tmp;
                }
                i++;
            }
            else{
                string tmp;
                while(i<n&&s[i]>='a'&&s[i]<='z'){
                    tmp+=s[i++];
                }
                st.top()+=tmp;
            }
        } return st.top();
    }
};
