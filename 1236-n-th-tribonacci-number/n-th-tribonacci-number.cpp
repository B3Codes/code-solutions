class Solution {
public:
    int tribonacciHelper(int n,vector<int>& memo) {
        if(memo[n] != -1)
            return memo[n];
        if(n==0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        
        memo[n] = tribonacciHelper(n-1, memo) + tribonacciHelper(n-2, memo) + tribonacciHelper(n-3, memo);

        return memo[n];
    }
    int tribonacci(int n) {
        // if(n == 0)
        //     return 0;
        //     if(n == 1 || n == 2)
        //         return 1;
            

        // vector<int> tri(n+ 1);
        // tri[0] = 0;
        // tri[1] = 1;
        // tri[2] = 1;

        // for(int i = 3;i<=n;i++) {
        //     tri[i] = tri[i-1] + tri[i-2] + tri[i-3];
        // }
 
        // return tri[n];

        // // recursion
        // if(n == 0)
        //     return 0;

        // if(n == 1 || n == 2)
        //     return 1;
        
        // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

        //Recursion with Memoization
        vector<int> memo(n+1, -1);
        return tribonacciHelper(n, memo);
    }
};