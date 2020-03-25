/*
 Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;

        //without count limit
        if(k > len/2){
            int sum = 0;
            for(int i = 1; i< len; ++i){
                auto profit = prices[i] - prices[i-1];
                sum += profit > 0 ? profit : 0;
            }
            return sum;
        }

        vector<vector<vector<int>>> dp(len,vector<vector<int>>(k+1,vector<int>(2,0)));

        for(int i = 0; i < len; ++i){
            for(int count = k; count >=1;count--){
                if(i-1 == -1){
                    dp[i][count][0] = 0;
                    dp[i][count][1] = -prices[i];
                    continue;
                }

                dp[i][count][0] = max(dp[i-1][count][0],dp[i-1][count][1]+prices[i]);
                dp[i][count][1] = max(dp[i-1][count][1],dp[i-1][count-1][0] - prices[i]);
            }
        }
        return dp[len-1][k][0];
    }
};

