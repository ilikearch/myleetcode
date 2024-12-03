class Solution {
    unordered_map<int, int> memo;
public:
    int integerReplacement(long long n) {
        if(n==1)return 0;
        if(memo.count(n))return memo[n];
        if(n%2==0){
            memo[n]=1+integerReplacement(n/2);
            return memo[n];
        }
        memo[n]=2+min(integerReplacement((n-1)/2),integerReplacement((n+1)/2));
        return memo[n];
    }
};
