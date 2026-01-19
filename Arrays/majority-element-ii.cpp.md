## Majority Element II

**LeetCode ID:** 229  
**Difficulty:** Medium

---

### Problem Statement

Given an integer array, return all elements that appear more than ⌊n / 3⌋ times. At most two such elements can exist.

---

### Approach

- Use the **extended Boyer–Moore Voting Algorithm**.
- Since an element must appear more than n/3 times, there can be at most two candidates.
- First pass selects potential candidates, second pass verifies their counts.

---

### Code (C++)

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 =0; // I wil use these variables to keep track of potential candidates
        int count1 = 0, count2 = 0; // The number of times they appear
        for(int num:nums){
            if(num==cand1){
                count1++; // If I get the same candidate again then I will increase its frequency
            }else if (num==cand2){
                count2++;
            }else if(count1==0){
                cand1 = num; // If I don't get the same candidates and the frequency of a candidate is 0 then I will assign this num as cand1
                count1++;
            }else if(count2==0){
                cand2 = num;
                count2++; // Updating the count value after assigning the candidate
            } else{
                count1--;
                count2--; // If it is a new candidate then I will reduce both the counts by 1. Here count basically shows how much a candidate is more than other candidates
            }
        }

            count1 = 0, count2 = 0; // I will verify the actual frequencies
            for(int num: nums){
                if(num==cand1) count1++;
                else if(num==cand2) count2++; // Using else if prevents double counting if cand1 = cand2
            }

            int n = nums.size();
            vector<int> result;
            if(count1>n/3) result.push_back(cand1);
            if(count2>n/3) result.push_back(cand2);
        return result;
    }
};
```

---

### Time Complexity

- **Time:** O(n)
- **Space:** O(1)

---

### Key Insight

For a frequency threshold of n/k, there can be at most k−1 valid elements; here, k = 3, so only two candidates need tracking.
