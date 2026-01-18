## Sort Colors

**LeetCode ID:** 75  
**Difficulty:** Medium  

---

### Problem Statement
Given an array containing only 0s, 1s, and 2s, sort the array in-place so that elements of the same color are adjacent, in the order 0, 1, 2.

---

### Approach
- Use the **Dutch National Flag algorithm**.
- Maintain three pointers to separate 0s, 1s, and 2s.
- Traverse the array once and swap elements into their correct regions.

---

### Code (C++)
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0,mid = 0, high = n-1;
        for(int i = 0;i<n;i++){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid]==1) mid++;
            else {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
