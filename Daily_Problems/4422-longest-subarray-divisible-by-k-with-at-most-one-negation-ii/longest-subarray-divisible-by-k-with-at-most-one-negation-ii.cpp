class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        vector<int> first(k,-1);
        first[0] = 0;

        long long sum = 0;
        int ans = 0;

        vector<int> last(k,-1);
        vector<int> best(k,-1);
        vector<int> seen;
        seen.push_back(0);
        vector<int> ptr(k,0);

        for(int r = 0; r<nums.size();r++){
            int pref = ((sum%k)+k)%k;

            if(first[pref]==-1){
                first[pref] = r;
                seen.push_back(pref);
            }

            int d = ((2LL*nums[r]%k)+k)%k;
            last[d] = r;

            while(ptr[d]<seen.size() && first[seen[ptr[d]]] <=last[d]){
                int t = seen[ptr[d]];
                int p = (t+d)%k;

                if(best[p]==-1)
                    best[p] = first[t];
                else
                    best[p] = min(best[p],first[t]);

                ptr[d]++;
            }

            sum += nums[r];
            int rem = ((sum%k)+k)%k;

            if(first[rem]!= -1){
                ans = max(ans, r+1 - first[rem]);
            }

            if(best[rem]!=-1){
                ans = max(ans, r+1 - best[rem]);
            }
        }

        return ans;
    }
};