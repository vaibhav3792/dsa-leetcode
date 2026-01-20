## Subarray Sum Equals K

**LeetCode ID:** 560  
**Difficulty:** Medium  

---

### Problem Statement
Given an integer array and an integer `k`, return the total number of continuous subarrays whose sum equals `k`.

---

### Approach
- Use **prefix sums** combined with a **hash map**.
- Track how many times a particular prefix sum has occurred.
- For each position, check if `(current_sum - k)` has appeared before.


---

### Code (C++)
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp; // I will use this map to keep track of the prefix Sum
        mpp[0] = 1; // To handle the cases where nums[0] = k
        int preSum = 0, cnt = 0;
        for(int i =0;i<nums.size();i++){
            preSum += nums[i]; 
            int remove = preSum - k; 

            cnt += mpp[remove]; // Add the number of times preSum - k appears in the array
            mpp[preSum] += 1; // Add the value/frequency of the current preSum in the map
        }
        return cnt;
    }
};
````

---

### Time Complexity

* **Time:** O(n)
* **Space:** O(n)

---

### Key Insight

If two prefix sums differ by `k`, the subarray between them sums to `k`.