- Agar humlog item ko exclude kar rahe hai to wo process hogaya hai aur knapsack call karte time n-1 ko call karenge
- Agar item ko include karna hai to hum us item ko phirse le sakte hai to call karte time n hi call hoga
- Other things are same.
- *Main difference is that **repetition of items** is allowed.*

## Code

```cpp
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<int> dp(capacity+1,0);
        
        for(int i = val.size()-1;i>=0;i--){
            for(int j = 1; j<=capacity;j++){
                
                int take = 0;
                if(j-wt[i]>=0){
                    take = val[i] + dp[j-wt[i]];
                } 
                    int noTake = dp[j];
                
                dp[j] = max(take,noTake);
            }
        }
        return dp[capacity];
    }
};
```