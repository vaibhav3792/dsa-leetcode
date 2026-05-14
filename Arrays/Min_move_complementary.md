
## Minimum Moves to Make Array Complementary

- LeetCode ID: 1674
- Difficulty: Medium

## Code
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2*limit + 2, 0);
        for(int i = 0; i<n/2;i++){
            int mn = nums[i];
            int mx = nums[n-1-i];
            if(mn>mx) swap(mn,mx);
            delta[2] +=2;
            delta[mn+1]--;
            delta[mn+mx]--;
            delta[mn+mx+1]++;
            delta[mx+limit+1]++;
        }

        int ans = n;
        int moves = 0;
        for(int t=2;t<=limit*2;t++){
            moves += delta[t];
            ans = min(ans,moves);
        }
        return ans;
    }
};
```