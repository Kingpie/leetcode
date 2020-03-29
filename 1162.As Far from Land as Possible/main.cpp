/*Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

 

Example 1:



Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation:
The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:



Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation:
The cell (2, 2) is as far as possible from all the land with distance 4.
 

Note:

1 <= grid.length == grid[0].length <= 100
grid[i][j] is 0 or 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//bfs
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<int> xdirect = {0,-1,0,1};
        vector<int> ydirect = {1,0,-1,0};
        int xlimit = grid.size()-1;
        int ylimit = grid[0].size()-1;

        for(int i = 0; i <= xlimit;++i){
            for(int j = 0; j <= ylimit;++j){
                if(grid[i][j]){
                    q.push(make_pair(i,j));
                }
            }
        }

        bool hasOcean = false;
        auto node = make_pair(-1,-1);
        while(!q.empty()){
            node = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int newx = node.first + xdirect[i];
                int newy = node.second + ydirect[i];

                if(newx >= 0&&newx <= xlimit&&newy>=0&&newy<=ylimit&&!grid[newx][newy]){
                    grid[newx][newy] = grid[node.first][node.second]+1;
                    q.push(make_pair(newx,newy));
                    hasOcean = true;
                }
            }
        }

        if(!hasOcean || node.first == -1){
            return -1;
        }

        return grid[node.first][node.second]-1;
    }
};