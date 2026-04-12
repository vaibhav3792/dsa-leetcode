- Matrix banate hai
- We don't get stack overflow error in this one. 
- Stack Overflow happens rarely so we can use memoization in general

---

- Recursive form ka base condition -> Bottom up ka initialization
```cpp
// Base Condition for recursion
    if(n==0 || W==0) return 0;

// Initialization for Bottom up
for(int i = 0;i<n+1;i++){
    for(int j = 0;j<W+1;j++){
        if(i==0 || j==0){
            t[i][j] = 0;
        }
    }
}
```
---

## Comparison

```cpp
// Recursion
if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }

// Tabulation
if(wt[i-1] <= j){
    t[i][j] = max(
        val[i-1] + t[i-1][j - wt[i-1]],
        t[i-1][j]
    );
}
```

```cpp
// Recursion
else if(wt[n-1]>W){
        return knapsack(wt,val,W,n-1);
    }

// Tabulation
else{
    t[i][j] = t[i-1][j];
}
```