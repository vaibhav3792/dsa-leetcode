## Code
```cpp
int static t[1001][1001];

int solve(int arr[], int i, int j){
    if(i>=j) return;

    if(t[i][j]!=-1) return t[i][j];

    int mn = INT_MAX;
    for(int k = i;k<j;k++){
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];

        if(temp<mn){
            temp = mn;
        }
    }

    return t[i][j] = mn;
}
```