- Number of nodes along the longest path between two leaf nodes
- Base Case and Hypothesis remain the same
- There will be change in the inductio code

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
int ans = max(temp, 1+l+r)
res = max(ans,res);

return temp;

```