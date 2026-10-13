class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(30,0);
        const int MOD = 1e9 + 7;
        for(int num: nums){
            for(int i = 0; i<30;i++){
                if(num & (1<<i)){
                    freq[i]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<k;i++){
            int x =0;
            for(int j = 0; j<30;j++){
                if(freq[j]>0){
                    x |= (1<<j);
                    freq[j]--;
                }
            }
            ans = (ans + 1LL*x*x)%MOD;
        }
        return ans;


    }
};