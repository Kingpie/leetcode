/*Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//bfs
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int numr = matrix.size();
        int numc = matrix[0].size();
        vector<pair<int,int>> around = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> result(numr, vector<int>(numc, INT_MAX));
        queue<pair<int,int>> que;
        for(int i = 0; i < numr; i++){
            for(int j = 0; j < numc; j++){
                if(matrix[i][j] == 0){
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int x = temp.first + around[i].first;
                int y = temp.second + around[i].second;
                if(x >= 0 && x < numr && y >= 0 && y < numc){
                    if(result[x][y] > result[temp.first][temp.second] + 1){
                        result[x][y] = result[temp.first][temp.second] + 1;
                        que.push({x, y});
                    }
                }

            }
        }
        return result;
    }
};

