class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        vector<long long> temp;
        for(auto& num: nums){
            temp.push_back(num*num);
        }
        sort(temp.begin(),temp.end());
        int n = nums.size();
        for(int i = 0; i<n;i++){
            if(i<n/2){
                ans -= temp[i];
            }else{
                ans += temp[i];
            }
        }
        return ans;
    }
};