## Next Permutation

**LeetCode ID:** 31  
**Difficulty:** Medium

---

### Problem Statement

Given an array of integers, rearrange it into the next lexicographically greater permutation. If such arrangement is not possible, rearrange it into the lowest possible order.

---

### Approach

- Identify the first position from the right where the order decreases.
- Swap this element with the smallest element greater than it on the right.
- Reverse the remaining suffix to get the next permutation.

---

### Code (C++)

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){ // Finding the breaking point
                ind = i;
                break;
            }
        }

        if(ind == -1){ // If we didn't get a breaking point
                reverse(nums.begin(),nums.end()); // This is for when we get the last permutation according to the lexicographial order
                return;
        }
        
        for(int i = n-1;i>=0;i--){
            if(nums[i]>nums[ind]){ // Finding the number just greater than nums[ind]
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        reverse(nums.begin() + ind + 1,nums.end());

    }
};
```
