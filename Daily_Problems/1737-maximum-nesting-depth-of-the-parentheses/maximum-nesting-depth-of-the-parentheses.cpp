class Solution {
public:
    int maxDepth(string s) {
        int curdep = 0;
        int ans = 0;
        for(auto it: s){
            if(it=='('){
                curdep++;
                ans = max(ans,curdep);
            } else if(it == ')') curdep--;
        }
        return ans;
    }
};