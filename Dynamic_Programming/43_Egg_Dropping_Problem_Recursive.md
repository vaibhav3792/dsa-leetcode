### Problem statement: 

You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break.

---
- Input: no of eggs, floor
- Need min attempts
- MCM Implementation
- If the egg is breaking at a particular floor then obviously it will break for all the above floors so we will eliminate those. Check for below floors.
- Min number of attempts in worst case
- Worst case:
    > Assume the outcome of every egg drop is the most inconvenient possible for you.
    - This is the reason we use max.
- Why not average case?

    - We are not minimizing expected drops.

    - We are minimizing the maximum number of drops we might ever need.

    - This guarantees success even in the most unlucky situation.

## Code

```cpp

int solve(int e, int f){
    if(f==0 || f==1){
        return f;
    }

// Since we have only one egg left we can't take risks so we have to search for the linearly from bottom till top. Hence we have to search for the remaining number of floors.
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