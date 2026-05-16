- Base Case
- Hypothesis
- Induction

## Code

```cpp
int solve(Node* root, int* res){

// Base condtion
if(root==nullptr) return 0;

// Hypothesis
int l = solve(root->left,res);
int r = solve(root->right,res);

// Induction
int temp = 1 + max(l,r);
int ans = max(temp, relation)
res = max(ans,res);

return temp;
}
```