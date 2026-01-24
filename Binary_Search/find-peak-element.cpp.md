## Find Peak Element

**LeetCode ID:** 162  
**Difficulty:** Medium  

---

### Problem Statement
Given an integer array where adjacent elements are not equal, find a peak element and return its index. A peak element is greater than its neighbors.

---

### Approach
- Use **binary search** instead of linear scan.
- At any index, compare the middle element with its right neighbor.
- Move towards the side that must contain a peak.

---

### Code (C++)
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() -1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid+1]){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};

```
### Complexity

- Time: O(log n)

- Space: O(1)

### Key Insight

If an element is smaller than its right neighbor, a peak must exist on the right side; otherwise, it exists on the left.

