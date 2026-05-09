- Everything remains the same. We are just applying memoization while calculating temp too.

## Code

```cpp

if(t[i][k]!=-1){
    left = t[i][k];
}else{
    left = solve(s,i,k);
}

if(t[k+1][j]!=-1){
    right = t[k+1][j];
} else{
    right = solve(s,k+1,j);
}

int temp = 1 + left + right;

```