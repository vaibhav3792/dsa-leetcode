- Prerequisites:
    - LCS
    - SCS
    - Print LCS

- In LCS we were skipping elements that were not common in both strings but here we have to include them in the result
- Similarly, in LCS we were stopping when either of the string indices reached 0, but in SCS we have to go on until both of the indices become 0

## Code

```cpp

int i = n;
int j = m;
string s = "";
while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
        s.push_back(a[i-1]);
        i--;
        j--;
    }
    else{
        if(dp[i][j-1]>dp[i-1][j]){
            s.push_back(b[j-1]);
            j--;
        }else{
            s.push_back(a[i-1]);
            i--;
        }
    }
}

while(i>0){
    s.push_back(a[i]);
    i--;
}

while(j>0){
    s.push_back(b[i]);
    j--;
}

```
