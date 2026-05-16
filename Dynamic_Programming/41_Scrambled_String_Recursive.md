- Constraints  
    - Binary Tree
    - No empty child

## Code

### Case 1 - Swap
```cpp

// if(solve(smaller a, smaller b) == true && 
// solve(small a, small b) == true)

if(solve(a.substr(0,i), b.substr(n-i,i)) == true &&
solve(a.substr(i,n-i),b.substr(0,n-i)) == true)

```

### Case 2 - No Swap

```cpp

if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i), b.substr(i,n-i))==true)

```

```cpp

if(Case1 || Case2) -> Scrambled String

```

### Base Condition

- Think of the smallest input
```cpp

if(a.length()!=b.length()) return false;
if(both empty) return true;
if(a.compare(b)==0) return true;
if(a.length()<=1) return false;
```

### Solve function

```cpp
solve(string a, string b){
    if(a.compare(b)==0) return true;
    if(a.length()<=1) return false;

    int n = a.length();
    bool flag = false;
    for(int i =1;i<n;i++){
        if(case1||case2){
            flag = true;
            break;
        }       
    }

    return flag;
}

```