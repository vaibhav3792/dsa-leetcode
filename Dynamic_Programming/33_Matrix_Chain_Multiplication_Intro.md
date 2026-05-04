1) MCM
2) Printing MCM
3) Evaluate Expression to True/ Boolean Parenthesization
4) Min/ Max value of an expression
5) Palindrome Partitioning
6) Scramble String
7) Egg Dropping Problem


## Identification
- string or array 
- i   k   j
- i -> j;  k+1 -> j 
- Base Condtion -> 
    - Think of the smallest valid input
    - Think of invalid input

## Format

```cpp

int solve(int arr[], int i, int j){
    if(i>j){
        return 0;
    }

    for(int k=i;k<j;k++){
        temp_ans = solve(arr,i,k) + solve(arr,k+1,j);

        ans = func(temp_ans);
    }

    return ans;
}

```
