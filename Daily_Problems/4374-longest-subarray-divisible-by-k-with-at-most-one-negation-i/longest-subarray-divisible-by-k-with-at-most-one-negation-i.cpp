class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_set<int> st;
        int sum = 0;
        int ans = 0;
        int rem, xrem;
        for(int l = 0; l<nums.size();l++){
            st.clear();
            sum = 0;
            for(int r = l; r<nums.size();r++){
                sum += nums[r];
                rem = ((sum%k) + k) % k;
                xrem = ((2LL*nums[r]%k)+k)%k;
                st.insert(xrem);
                if(rem==0 || st.count(rem)){
                    ans = max(ans,r-l+1);
                }
            }
            
        }
        return ans;
    }
};