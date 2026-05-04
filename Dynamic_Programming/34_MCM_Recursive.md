- arr[] = {10,20,30,40};
- Ai = arr[i-1] * arr[i]
- Find values of i and j. 
    - Here i = 1 and j = n-1
- Find the correct Base Condition.
    - Here it is i>=j instead of i>j.
    - At i==j we get size = 0 so we ignore it
- Move k from i to j
     - Way 1: k=i, k = j-1, for (i to k), for(k+1 to j)
     - Way 2: k=i+1, k=j, for (i to k-1), for(k to j)
- Calculate ans for temp_ans

## Code

```cpp

int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }

    for(int k = i; k<j;k++){
        int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];

        if(temp_ans<mn){
            mn = temp;
        }
    }

    return mn;
}


```