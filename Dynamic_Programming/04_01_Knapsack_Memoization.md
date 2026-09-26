- Prefer using Recursive Code and Memoize it instead of using Bottom Up Approach

- In the knapsack function, W and n change so we will initialize a matrix t[n+1][W+1] with the values as -1

- We will use it for memoization. If a value like t[3][2] appears and is present in the matrix then we don't call recursion for it. If not present then do recursion and store its value in the matrix.

- ## Changes in the code

- Original Code: 
```cpp 
int knapsack(int wt[], int val[], int W, int n){
    // Base Condition
    if(n==0 || W==0) return 0;

    // Choice Diagram
    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W){
        return knapsack(wt,val,W,n-1);
    }
}
```

- Updated Code: 

```cpp
int static t[102][1002]; // Assuming that constraints are n<=100 and W<=1000
memset(t,-1, sizeof(t)); // This will be inside main function

int knapsack(int wt[], int val[], int W, int n){
    // Base Condition
    if(n==0 || W==0) return 0;
    if(t[n][W]!=-1){
        return t[n][W];
    }

    // Choice Diagram
    if(wt[n-1]<=W){
        return t[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W){
        return t[n][W] = knapsack(wt,val,W,n-1);
    }
}

```