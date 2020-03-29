/*In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<int> xdirect = {0,-1,0,1};
        vector<int> ydirect = {1,0,-1,0};

        int m = grid.size();
        if(m == 0) return -1;
        int n = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                    grid[i][j] = -1;
                }else if(grid[i][j] ==1){
                    cnt++;
                }
            }
        }

        if(q.empty() && cnt==0) return 0;

        int level = -1;
        while(!q.empty()){
            level++;
            int curLevelNum = q.size();
            while(curLevelNum-- > 0){
                auto node = q.front();
                q.pop();
                for(int i = 0; i < 4;++i){
                    int newx = node.first+xdirect[i];
                    int newy = node.second+ydirect[i];
                    if(newx>=0&&newx<m&&newy>=0&&newy<n&&grid[newx][newy]==1){
                        grid[newx][newy] = -1;
                        q.push(make_pair(newx,newy));
                        cnt--;
                    }
                }
            }
        }
        return cnt==0?level:-1;
    }
};