/*You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walls-and-gates
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0)
            return;
        int inf = INT_MAX;
        int m = rooms.size();
        int n = rooms[0].size();

        vector<int> xdirect = {0,-1,0,1};
        vector<int> ydirect = {1,0,-1,0};
        vector<vector<int>> flag(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rooms[i][j] == 0){
                    q.push(make_pair(i,j));
                    flag[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int curLevelNum = q.size();
            while(curLevelNum-->0){
                auto node = q.front();
                q.pop();
                for(int k = 0; k < 4;++k){
                    int newx = node.first+xdirect[k];
                    int newy = node.second+ydirect[k];
                    if(newx>=0&&newx<m&&newy>=0&&newy<n&&!flag[newx][newy]&&rooms[newx][newy]!=-1){
                        if(rooms[newx][newy]==inf){
                            rooms[newx][newy] = rooms[node.first][node.second]+1;
                        }
                        q.push(make_pair(newx,newy));
                        flag[newx][newy] = 1;
                    }
                }

            }
        }
    }
};

