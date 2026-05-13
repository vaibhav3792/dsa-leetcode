- Input: String -> T, F, AND, OR, XOR
- Output: Int
- Steps:
    1) Find i and j
    2) Base Condition
    3) k loop
    4) temp -> ans
- 

## Code

```cpp

#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a boolean expression given two operands and an operator
bool evaluate(bool left, bool right, char op) {
    if (op == '&') return left & right;
    if (op == '|') return left | right;
    return left ^ right; // for '^'
}

// Recursive function to count the number of ways s[i...j] can evaluate to 'req'
int countRecur(int i, int j, bool req, string &s) {
    // Base case: if the substring is a single operand (T/F)
    if (i == j) {
        return (req == (s[i] == 'T')) ? 1 : 0;
    }

    int ways = 0;

    // Partition only at operator positions → they lie at odd indices
    for (int k = i + 1; k < j; k += 2) {
        // Count ways for left and right subexpressions
        int leftTrue  = countRecur(i, k - 1, true, s);
        int leftFalse = countRecur(i, k - 1, false, s);
        int rightTrue  = countRecur(k + 1, j, true, s);
        int rightFalse = countRecur(k + 1, j, false, s);

        // Combine results based on operator at position k
        if (evaluate(true, true, s[k]) == req)
            ways += leftTrue * rightTrue;
        if (evaluate(true, false, s[k]) == req)
            ways += leftTrue * rightFalse;
        if (evaluate(false, true, s[k]) == req)
            ways += leftFalse * rightTrue;
        if (evaluate(false, false, s[k]) == req)
            ways += leftFalse * rightFalse;
    }

    return ways;
}

// Wrapper function: returns number of ways to evaluate entire expression to True
int countWays(string s) {
    int n = s.length();
    return countRecur(0, n - 1, true, s);
}

int main() {
    string s = "T|T&F^T";
    cout << countWays(s);
    return 0;
}

```