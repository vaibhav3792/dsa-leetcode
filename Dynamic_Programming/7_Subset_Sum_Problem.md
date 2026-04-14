## Subset Problem

- t[n+1][W+1] ka matrix banega
- 0 and 1 se initialize karo
- First cell pe dhyaan dena. Agar arr ka size 0 hai aur sum 0 chahiye to ye case possible hai
- Agar array ka size 0 hai aur kuch sum chahiye to obviously not possible.
- Sum = 0 kisi bhi size ke array ke liye satisfy ho jayega

## Similarity with Knapsack
- Knapsack me 2 array hota hai, wt aur val. Aur ek capacity W
- Is Q me sum is our capacity, i.e. W.
- Ek hi array diya hai to usko wt maan lo. Ignore val array
- t[n+1][sum+1]
> wt[] -> arr[]

> W-> sum

## Code

> Q. Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

```cpp
class Solution {
  public:
    bool knapsack(vector<int>& arr, int n, int sum, 
    vector<vector<int>>& t){
        if(sum==0) return 1;
        
        if(n<=0) return 0;
        
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        
        if(arr[n-1]>sum){
            return t[n][sum] = knapsack(arr,n-1,sum,t);
        }else{
            return t[n][sum] = knapsack(arr,n-1,sum,t) || knapsack(arr,n-1,sum-arr[n-1],t);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(n+1,vector<int>(sum+1,-1));
        return knapsack(arr,n,sum,t);
    }
};

```