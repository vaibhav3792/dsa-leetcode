class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = nums[0];
        const long long NEG = -(1LL << 60);
        long long plus0 = nums[0];
        long long minus0 = NEG;
        long long plus1 = NEG;
        long long minus1 = NEG;

        long long prevPlus0 = NEG;
        long long prevMinus0 = NEG;

        for(int i = 1; i<nums.size();i++){
            long long x = nums[i];
            long long newPlus0 = max(x,minus0 + x);
            long long newMinus0 = plus0 - x;

            long long newPlus1 = max({x, minus1+x, prevMinus0 + x});
            long long newMinus1 = max(plus1-x, prevPlus0 - x);

            prevPlus0 = plus0;
            prevMinus0 = minus0;

            plus0 = newPlus0;
            plus1 = newPlus1;
            minus0 = newMinus0;
            minus1 = newMinus1;

            ans = max({ans,plus0,plus1,minus0,minus1});
        }
        return ans;
    }
};