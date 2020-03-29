/*You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-from-all-buildings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//before optimized
class Solution {
public:
    int bfs(const vector<vector<int>>& grid,int x, int y,int building){
        vector<int> xdirect = {0,-1,0,1};
        vector<int> ydirect = {1,0,-1,0};
        vector<vector<int>> flag(grid.size(),vector<int>(grid[0].size()));
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        flag[x][y] = 1;

        int xlimit = grid.size();
        int ylimit = grid[0].size();
        int level = 0,sum=0,reachable = 0,curLevelNum = 0;
        while(!q.empty()){
            level++;
            curLevelNum = q.size();
            while(curLevelNum-- > 0){
                auto node = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i){
                    int newx = node.first+xdirect[i];
                    int newy = node.second+ydirect[i];
                    if(newx >=0&&newx<xlimit&&newy>=0&&newy<ylimit&&!flag[newx][newy]&&grid[newx][newy]!=2){
                        if(grid[newx][newy]==1){
                            reachable++;
                            sum += level;
                        }else{
                            q.push(make_pair(newx,newy));
                        }
                        flag[newx][newy] = 1;
                    }
                }
            }
        }
        if(reachable < building){
            return -1;
        }else{
            return sum;
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        vector<pair<int,int>> blank;
        int building = 0;
        for(int i = 0; i < grid.size();++i){
            for(int j = 0; j < grid[0].size();++j){
                if(grid[i][j] == 0){
                    blank.push_back(make_pair(i,j));
                }else if(grid[i][j] == 1){
                    ++building;
                }
            }
        }

        int minSum = INT_MAX;
        for(auto t:blank){
            int sum = bfs(grid,t.first,t.second,building);
            if(sum >= 0)
                minSum = min(minSum,sum);
        }
        return minSum == INT_MAX?-1:minSum;
    }
};

