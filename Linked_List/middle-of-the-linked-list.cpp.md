## Middle of the Linked List

**LeetCode ID:** 876  
**Difficulty:** Easy  

---

### Problem Statement
Given the head of a singly linked list, return the middle node.  
If there are two middle nodes, return the second one.

---

### Approach
- Use two pointers moving at different speeds.
- The slow pointer moves one step at a time.
- The fast pointer moves two steps at a time.

---

### Key Insight
When the fast pointer reaches the end, the slow pointer will be at the middle due to the 2:1 speed ratio.

---

### Time Complexity
- **Time:** O(n)
- **Space:** O(1)

---

### Code (C++)
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
