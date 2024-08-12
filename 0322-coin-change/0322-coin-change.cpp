class Solution {
public:
    // int rec(vector<int> &coins,int amount)
    // {
    //     // base case
    //     if(amount == 0)
    //     return 0;

    //     int mini = INT_MAX;
    //     for(int i=0; i<coins.size(); i++)
    //     {
    //         // find ans using ith coin
    //         int recAns = 0;
    //         // call rec for valid amount i.e if amount-coins[i] >= 0 
    //         if(amount - coins[i] >= 0)
    //         {
    //             recAns = rec(coins,amount-coins[i]);

    //             if(recAns != INT_MAX)
    //             {
    //                 // current coin + recAns
    //                 int ans = 1 + recAns;
    //                 mini = min(ans,mini);
    //             }
    //         }
    //     }
    //     return mini;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int ans = rec(coins,amount);

    //     if(ans == INT_MAX)
    //     return -1;
    //     else
    //     return ans;
    // }

    int solveUsingMemo(vector<int> &coins,int amount,vector<int> &dp)
    {
        // base case 
        if(amount == 0)
        return 0;

        // previously stored ans
        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            if(amount - coins[i] >= 0)
            {
                int recAns = solveUsingMemo(coins,amount-coins[i],dp);
                if(recAns != INT_MAX)
                {
                    int ans = 1 + recAns;
                    mini = min(mini,ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount){
        // create dp array
        int n = amount;
        vector<int> dp(n+1,-1);

        int ans = solveUsingMemo(coins,amount,dp);
        if (ans == INT_MAX) return -1;

        return ans;
    }
};