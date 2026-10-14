class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        int i = 0;
        while(i<n){
            int r = nums[i]%k;
            int j = i;

            while(j<n && nums[j]%k==r) j++;
            int len = j-i;

            if(r==0) ans = max(ans,len);
            else{
                int d = k/gcd(k,r);
                int temp = ((len-1)/d)*d+1;
                ans = max(ans,temp);
            }
            i = j;
        }
        return ans;
    }
};