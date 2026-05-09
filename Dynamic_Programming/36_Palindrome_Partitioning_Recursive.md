## Code

```cpp
int solve(string s, int i, int j){
    if(i>=j) return 0;
    if(isPalindrome(s,i,j)) return 0;

    int mn = INT_MAX;
    for(int k = i; k = j-1; k++){
        int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
        if(temp< mn){
            mn = temp;
        }
    }

    return mn;
}

```