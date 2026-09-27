class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i = 0; i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j = st.top();
                st.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }

        int i = 0;
        int dir =1;
        string ans = "";
        while(i<s.size()){
            if(s[i]=='(' || s[i]==')'){
                i = mp[i];
                dir = -dir;
            } else{
                ans += s[i];
            }
            i+=dir;
        }

        return ans;
    }
};