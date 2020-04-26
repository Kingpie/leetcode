/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=grid.size()||i<0)
            return;
        if(j>=grid[0].size()||j<0)
            return;
        if(grid[i][j] == '1'){
            grid[i][j]='0';
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size();++i){
            for(int j = 0; j < grid[0].size();++j){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

