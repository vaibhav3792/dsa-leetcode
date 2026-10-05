class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int inner;
        stack<int> st;
        st.push(0);
        for(char ch: s){
            if(ch=='('){
                st.push(0);
            }
            else if(ch==')'){
                inner = st.top();
                st.pop();
                int contri = inner == 0 ? 1:2*inner;
                st.top() += contri;
            }
        }
        return st.top();
    }
};