- An additional constraint here is that the node can only return itself only when it is a leaf node

## Code

```cpp

int solve(Node* root, int& res){
    if(root==nullptr) return 0;

    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = max(l,r) + root->val;
    if(root->left==nullptr && root->right==nullptr){
        temp = max(temp,root->val);
    }
    int ans = max(temp,root->val + l + r);
    res = max(ans,res);

    return temp;
    
}

```