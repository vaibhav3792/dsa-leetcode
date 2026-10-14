class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        for(int i = 0; i<nums.size();i++){
            int r = (nums[i]%k);
            int j = i+1;
            while(j<nums.size() && nums[j]%k==r){
                int len = j-i+1;
                if((len-1)*r %k==0) ans = max(ans,len);
                j++;
            }
        }
        return ans;
    }
};