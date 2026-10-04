class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char ch: s){
            if(ch=='('){
                low++;
                high++;
            }
            else if(ch==')'){
                low = max(0,low-1);
                high--;
                if(high<0) return false;
            } else{
                low = max(0,low-1);
                high++;
            }
        }
        return low == 0;
    }
};