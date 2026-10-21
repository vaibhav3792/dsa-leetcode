class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(),t.end());
        int n = t.size();

        if(s==t) return 0;
        if(n==2) return -1;

        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;

        char mn = t[0];
        char mx = t[n-1];

        if(s.find(mn)<n-1) return 2;

        if(s.rfind(mx)>0) return 2;

        return 3;

    }
};