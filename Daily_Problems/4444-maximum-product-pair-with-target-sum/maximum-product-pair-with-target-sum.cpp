class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int mx = INT_MIN;
        vector<int> ans = {-1,-1};
        for(int i = 0; i<nums.size();i++){
            for(int j = 0; j<nums.size();j++){
                if(nums[i]>nums[j] && (nums[i] + nums[j] == target)){
                    int temp = nums[i] * nums[j];
                    if(temp>mx){
                        mx = temp;
                        ans = {i,j};
                    }
                }
            }
        }
        return ans;
    }
};