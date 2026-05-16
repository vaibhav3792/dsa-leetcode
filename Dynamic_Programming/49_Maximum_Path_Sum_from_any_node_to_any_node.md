- Similar code to diamter of a binary tree
- Be careful of the negative values

## Code

```cpp

int solve(Node* root, int& res){
    if(root==nullptr) return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = max(max(l,r) + root.val, root.val);
    int ans = max(temp, l+r+root.val);
    res = max(ans,res);
    return temp;
}

```