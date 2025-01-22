class Solution {
public:
    // int coinChangeHelper(vector<int>& coins, unordered_map<int, int>& memo, int amount) {
    //     if(amount < 0)
    //         return INT_MAX;
    //     if(amount == 0)
    //         return 0;
        
    //     if(memo.find(amount) != memo.end()) {
    //         return memo[amount];
    //     }

    //     int minCoin = INT_MAX;
        
    //     for(int coin: coins) {
    //         int result = coinChangeHelper(coins, memo, amount - coin);
    //         if(result != INT_MAX)
    //             minCoin = min(minCoin, result + 1);
    //     }

    //     memo[amount] = minCoin;

    //     return minCoin;
        
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     unordered_map<int, int> memo;
    //     int result = coinChangeHelper(coins, memo, amount);
    //     return (result != INT_MAX ? result : -1);
    // }

   


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1;i<amount+1;i++){
            for(int coin: coins){
                if(coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1); 
            }
        }

        return (dp[amount] != INT_MAX ? dp[amount] : -1);
    }
};