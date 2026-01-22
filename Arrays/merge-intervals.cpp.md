## Merge Intervals

**LeetCode ID:** 56  
**Difficulty:** Medium  

---

### Problem Statement
Given an array of intervals where each interval is represented as `[start, end]`, merge all overlapping intervals and return the resulting set of non-overlapping intervals.

---

### Approach
- Sort intervals based on their start time.
- Traverse the intervals and merge overlapping ones by extending the end time.
- Add non-overlapping intervals directly to the result.

---

### Code (C++)
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {}; // If there are no intervals return empty array

        vector<vector<int>> merged; // I will store the answer in this array
        
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);

        for(int i = 1;i<intervals.size();i++){
            vector<int> & last = merged.back();
            vector<int> & current = intervals[i];
            if(current[0]<= last[1]){
                last[1] = max(last[1],current[1]);
            } else{
                merged.push_back(current);
            }
        }
        return merged;
    }
};

```
---

### Time Complexity

- **Time**: O(n log n)

- **Space**: O(n) (for output)