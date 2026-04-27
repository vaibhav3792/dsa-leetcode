- Substring is consecutive but not subsequence
- Base Condition
    - Think of the smallest valid input
    - In this case it could be an empty string of length 0
    - If both the strings are empty then LCS = 0
- For strings X and Y with lengths n and m respectively
    ```cpp
    if(n==0 || m==0){
        return 0;
    }
    ```
- Choice Diagram
    - X: 'abcdgh'
    - Y: 'abedfhr'
    ```cpp
    if(X[n-1]==Y[m-1]){
        return 1 + LCS(X,Y,n-1,m-1);
    } else{
        return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }

## Code
```cpp
    int LCS(string X, string Y, int n, int m){
        // Base Condition
        if(n==0 || m==0){
        return 0;
        }  
        
        // Choice Diagram
        if(X[n-1]==Y[m-1]){
            return 1 + LCS(X,Y,n-1,m-1);
        } else{
            return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
        }
    }
```