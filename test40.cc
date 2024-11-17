class Solution {
public:
    // 计算 x 的 n 次幂
    double myPow(double x, int n) {
        // 当 n 为 0 时，任何数的 0 次幂都为 1
        if (n == 0) {
            return 1.0;
        } 
        // 当 n 为偶数时，利用 x^(2n) = (x^2)^n 的性质，递归计算 x^2 的 n/2 次幂
        else if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } 
        // 当 n 为奇数时，将 x^(n) 拆分为 x * x^(n-1)，递归计算 x^2 的 (n-1)/2 次幂
        else {
            if (n > 0)
                return myPow(x * x, n / 2) * x; // n 为正数时，乘以 x
            else {
                return myPow(x * x, n / 2) * (1.0 / x); // n 为负数时，除以 x
            }
        }
    }
};
