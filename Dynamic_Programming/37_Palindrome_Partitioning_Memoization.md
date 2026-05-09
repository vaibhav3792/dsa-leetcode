## Code

```cpp
int static t[1001][1001];

int solve(string s, int i, int j){
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];

    if(isPalindrome(s,i,j)) return 0;

    int mn = INT_MAX;

    for(int k = i;k<j;k++){
        int temp = 1 + solve(s,i,k) + solve(s,k+1,j);
        if(temp<mn){
            mn = temp;
        }
    }
    return mn;
    
}

bool isPalindrome(string s, int i, int j){
    if(i==j) return true;
    if(i>j) return true;

    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }

    return true;
}

```