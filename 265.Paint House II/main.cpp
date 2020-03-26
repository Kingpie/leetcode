/*There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-house-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class SolutionMyAnswer {
public:

    int getMinByIndex(vector<vector<int>>& dp,int index,int target,int len){
        int minCost = INT_MAX;
        for(int i = 0; i < len; ++i){
            if(i != target)
                minCost = min(minCost,dp[index][i]);
        }
        return minCost;
    }

    int minCostII(vector<vector<int>>& costs) {
        int len = costs.size();
        if(len == 0) return 0;
        int k = costs[0].size();
        if(len == 1){
            int minCost = INT_MAX;
            for(int i = 0; i < k;++i){
                minCost = min(minCost,costs[0][i]);
            }
            return minCost;
        }

        vector<vector<int>> dp(len,vector<int>(k));

        dp[0] = costs[0];

        for(int i = 1; i < len; ++i){
            for(int j = 0; j < k; ++j){
                dp[i][j] = costs[i][j] + getMinByIndex(dp, i-1, j, k);
            }
        }

        int minCost = INT_MAX;
        for(int i = 0; i < k; ++i){
            minCost = min(minCost,dp[len-1][i]);
        }
        return minCost;
    }
};

class SolutionBestAnswer {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0)
            return 0;
        //每次只保留本轮最小和第二小元素及其对应下标
        vector<pair<int, int>> cur_min(2, make_pair(INT_MAX, INT_MAX));
        vector<pair<int, int>> pre_min(2, make_pair(0, -1));    //设一个不存在的坐标，保证遇到最小即可更新
        int tmp;
        for(int i=0;i<costs.size();i++){
            for(int j=0;j<costs[0].size();j++){
                if(j == pre_min[0].second){ //如果这个房子是上一次最小的方案刷的房子
                    tmp = pre_min[1].first + costs[i][j]; //那么只能用上一次第二小的方案
                }
                else {
                    tmp = pre_min[0].first + costs[i][j];   //不然就可以用最小方案
                }
                if(tmp < cur_min[0].first){ //如果这是本轮到目前为止最小方案
                    cur_min[1] = cur_min[0];    //前面的最小方案去第二小
                    cur_min[0] = make_pair(tmp, j); //保存这种方案为最小
                }
                else if(tmp < cur_min[1].first){    //如果这种方案是当前第二小方案
                    cur_min[1] = make_pair(tmp, j); //保存
                }
            }
            pre_min = cur_min;
            cur_min[0] = make_pair(INT_MAX, INT_MAX);
            cur_min[1] = make_pair(INT_MAX, INT_MAX);
        }
        return pre_min[0].first;
    }
};

