class Solution {
public:
    // bool isUgly(int num)
    // {
    //     if(num <= 0) return false;
        
    //     while(num % 2 == 0) num/=2;
    //     while(num % 3 == 0) num/=3;
    //     while(num % 5 == 0) num/=5;

    //     return num == 1;
    // }
    // int nthUglyNumber(int n) {
    //     int count = 0;
    //     int current = 1;

    //     while(count < n)
    //     {
    //         if(isUgly(current))
    //         {
    //             count++;
    //         }
    //         current++;
    //     }
    //     return current - 1;
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;

        for(int i = 1; i < n; ++i) {
            int twoMul = 2 * dp[p1];
            int threeMul = 3 * dp[p2];
            int fiveMul = 5 * dp[p3];
            dp[i] = min({twoMul, threeMul, fiveMul});

            if(dp[i] == twoMul) p1++;
            if(dp[i] == threeMul) p2++;
            if(dp[i] == fiveMul) p3++;
        }

        return dp[n-1];
    }
};