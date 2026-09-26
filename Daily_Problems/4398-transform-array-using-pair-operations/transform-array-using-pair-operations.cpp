class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(accumulate(source.begin(),source.end(),0LL) != accumulate(target.begin(),target.end(),0LL)) return false;

        return true;
    }
};