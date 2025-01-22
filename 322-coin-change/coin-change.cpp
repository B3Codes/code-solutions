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

   


    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> dp(amount + 1, INT_MAX);
    //     dp[0] = 0;

    //     for(int i = 1;i<amount+1;i++){
    //         for(int coin: coins){
    //             if(coin <= i && dp[i - coin] != INT_MAX)
    //                 dp[i] = min(dp[i], dp[i - coin] + 1); 
    //         }
    //     }

    //     return (dp[amount] != INT_MAX ? dp[amount] : -1);
    // }


    /* using BFS approach */

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        queue<pair<int, int>> q;
        q.push({0,0});  // start from amount = 0, coins = 0

        vector<int> visited(amount + 1, false);
        visited[0] = true;

        while(!q.empty()) {
            auto [currentAmount, steps] = q.front();
            q.pop();

            for(int coin: coins) {
                int nextAmount = currentAmount + coin;

                // if target amount is reached, return the steps
                if(nextAmount == amount) return steps + 1;

                // if amount is valid and still is not reached
                if(nextAmount < amount + 1 && !visited[nextAmount]) {
                    visited[nextAmount] = true;
                    q.push({nextAmount, steps + 1});
                }

            }
         }

         return -1;
    }
};