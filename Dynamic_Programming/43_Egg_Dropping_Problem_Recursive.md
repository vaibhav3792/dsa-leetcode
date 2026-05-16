### Problem statement: 

You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break.

---
- Input: no of eggs, floor
- Need min attempts
- MCM Implementation
- If the egg is breaking at a particular floor then obviously it will break for all the above floors so we will eliminate those. Check for below floors.
- Min number of attempts in worst case

## Code

```cpp

int solve(int e, int f){
    if(f==0 || f==1){
        return f;
    }

    if(e==1){
        return f;
    }

    int mn = INT_MAX;
    for(int k =1;k<=f;k++){
        int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn = min(mn,temp);
    }

    return mn;

}

```