class Solution {
public:
    int minInsertions(string s) {
        
        int open = 0;
        int req = 0;

        int i = 0;
        while (i < s.size()) {
            char ch = s[i];
            if (ch == '(') {
                open++;
                i++;
            } else {
                if (open) {
                    open--;
                } else {
                    req++;
                }

                if (i < s.size() - 1 && s[i + 1] == ')') {
                    i += 2;
                } else {
                    req++;
                    i++;
                }
            }
            
        }

        return req + open * 2;
    }
};