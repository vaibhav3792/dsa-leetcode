class Solution {
public:
    int dist(char a, char b){
        int d = abs(a-b);
        return min(d,10-d);
    }
    int minRotations(int n, string s) {
        int og_cost = dist('0',s[0]);
        for(int i = 1; i<n;i++){
            og_cost += dist(s[i],s[i-1]);
        }

        int cand = 0;
        int ans = og_cost - dist('0',s[0]) + dist('0',s[n-1]);
        for(int k = 1; k<n;k++){
            cand = og_cost - dist(s[k],s[k-1]) + dist(s[k-1],s[n-1]);
            ans = min(cand,ans);
        }
        return ans;
    }
};