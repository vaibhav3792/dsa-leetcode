- We use tabulation as there is a risk of stack overflow in recursive and memoization
- Jo values change ho rahe hote hai unko use karke matrix banate hai. 
- In this case it is m and n which are the length of strings X and Y respectively. 
- Base Condition -> Initialization
- Remember that this is the bottom up approach. We are slowly building up values from bottom to the top.
- Remembering this makes it easier to visualize and understand. Don't try to break it from top to bottom.
``` cpp
int func(Input){
    // Base Condition

    // Choice Diagram

    //------//
    if(X[m-1]==Y[n-1]){
        return t[m][n] + LCS(X,Y,m-1,n-1);
        // t[m][n] = 1 + t[m-1][n-1];
     } else{
        return t[m][n] + max(LCS(X,Y,m-1,n),LCS(X,Y,m,n-1));
        // t[m][n] = max(t[m][n-1],t[m-1][n]);
     }
}
```


## Code

```cpp

// m -> i
// n -> j

int t[m+1][n+1];
// Initialization
for(int i = 0;i<=m;i++){
    for(int j = 0;j<=n;j++){
        if(i==0 || j==0){
            t[i][j] = 0;
        }
    }
}

for(int i = 1; i<=m;i++){
    for(int j = 1;j<=n;j++){
        if(X[i-1]==Y[j-1]){
            t[i][j] = 1 + t[i-1][j-1];
        } else{
            t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
}

```