- We were blindly assuming that if a given function is not solved then both its sub problems will also not be solved
- But it can happen that one of the subproblems had been solved previously while the other one wasn't.
- We can optimize the code for it.

## Code

```cpp

// Original Code
int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));

```
```cpp

// Optimized Code
if(t[e-1][k-1]!=-1){
    int low = t[e-1][k-1];
} else{
    int low = solve(e-1,k-1);
    t[e-1][k-1] = low;
}

if(t[e][f-k]!=-1){
    int high = t[e][f-k];
} else{
    int high = solve(e,f-k);
    t[e][f-k] = high;
}

```
