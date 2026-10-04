class Solution {
public:
    int minRotations(string s) {
        int res = 0;
        int cur = '0';
        for(char ch: s){
            int d = abs(ch-cur);
            res += min(d,10-d);
            cur = ch;
        }
        return res;
    }
};