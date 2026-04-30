-  Pehle LCS use karke matrix fill kar lena hai, uske baad reverse me aana hai
- Jaha par dono string ka letter same mile, wo index ka letter ko result string me add karna hai
- Ye loop me tab tak chalega jab tak humlog i = 0 || j==0 tak na pahuch jaaye
- Final string ke liye result ko reverse karna hoga as we are moving from last to first

## Code

```cpp
int i = m, int j = n; // m and n are length of strings a and b respectively

string s;

while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
        s.push_back(a[i-1]);
        i--;
        j--;
    }
    if(dp[i][j-1]>dp[i-1][j]){
        j--;
    }else{
        i--;
    }
}

reverse(s.begin(), s.end());

```