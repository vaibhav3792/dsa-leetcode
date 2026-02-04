## Check if a Binary Tree is a Heap (Index-Based Method)

**Problem Type:** Binary Tree  
**Heap Type:** Max Heap  

---

### Problem Statement
Given the root of a binary tree, determine whether the tree satisfies the properties of a max heap using node indexing.

---

### Approach
- Count the total number of nodes in the tree.
- Assign indices to nodes assuming array representation.
- Verify:
  1. No node has an index ≥ total node count (completeness).
  2. Every parent node satisfies the max-heap property.

---

### Key Insight
In a heap, mapping nodes to array indices ensures completeness, and any node violating index bounds or parent dominance breaks the heap property.

---

### Time Complexity
- **Time:** O(n)
- **Space:** O(h) (recursion stack)

---

### Code (C++)
```cpp
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isHeapUtil(TreeNode* root, int index, int nodeCount) {
    if (!root) return true;

    // Check completeness
    if (index >= nodeCount) return false;

    // Check max-heap property
    if (root->left && root->val < root->left->val) return false;
    if (root->right && root->val < root->right->val) return false;

    return isHeapUtil(root->left, 2 * index + 1, nodeCount) &&
           isHeapUtil(root->right, 2 * index + 2, nodeCount);
}

bool isHeap(TreeNode* root) {
    int nodeCount = countNodes(root);
    return isHeapUtil(root, 0, nodeCount);
}
