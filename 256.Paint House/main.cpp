/*There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
             Minimum cost: 2 + 5 + 3 = 10.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-house
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if(len == 0) return 0;
        if(len == 1) return min(min(costs[0][0],costs[0][1]),costs[0][2]);

        int dp0 = costs[0][0];
        int dp1 = costs[0][1];
        int dp2 = costs[0][2];
        for(int i = 1; i < len;++i){
            int temp0 = dp0;
            int temp1 = dp1;
            dp0 = costs[i][0] + min(temp1,dp2);
            dp1 = costs[i][1] + min(temp0,dp2);
            dp2 = costs[i][2] + min(temp0,temp1);
        }
        return min(min(dp0,dp1),dp2);
    }
};
