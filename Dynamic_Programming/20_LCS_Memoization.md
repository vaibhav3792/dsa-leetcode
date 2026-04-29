- Check for constraints and then initialize the matrix dp or t with a size greater than the constraints by 1
- DP generally tab hi use hoga jab 2 function call ho raha ho, ek ke liye nai lagega

## Code

```cpp
static int t[][]; // constraints
memset(t,-1,sizeof(t));

int LCS(string X, string Y, int m, int n){
     if(n==0 || m==0){
        return 0;
     }

     if(t[m][n]!=-1){
        return t[m][n];
     }

     if(X[m-1]==Y[n-1]){
        return t[m][n] + LCS(X,Y,m-1,n-1);
     } else{
        return t[m][n] + max(LCS(X,Y,m-1,n),LCS(X,Y,m,n-1));
     }
}
```