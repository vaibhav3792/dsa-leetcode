## Remove Duplicates from Sorted Array

**LeetCode ID:** 26  
**Difficulty:** Easy  

---

### Problem Statement
Given a sorted array, remove the duplicates in-place such that each element appears only once and return the new length.

---

### Approach
- Use two pointers to track the position of unique elements.
- One pointer scans the array, the other marks where the next unique element should go.
- Overwrite duplicates in-place.

---

### Key Insight
Because the array is sorted, all duplicates are adjacent, allowing a single pass with a write pointer.

---

### Time Complexity
- **Time:** O(n)
- **Space:** O(1)

---

### Code (C++)
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
