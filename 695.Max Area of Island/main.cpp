/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int getArea(vector<vector<int>>& grid,int i,int j){
        if(i>= grid.size()||i<0)
            return 0;
        if(j>=grid[0].size()||j<0)
            return 0;
        if(grid[i][j]){
            grid[i][j]=0;
            return 1+getArea(grid,i+1,j)+getArea(grid,i-1,j)+getArea(grid,i,j+1)+getArea(grid,i,j-1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0,maxArea=0;
        for(int m=0;m<grid.size();++m){
            for(int n = 0;n<grid[0].size();++n){
                if(grid[m][n]){
                    area = getArea(grid,m,n);
                    maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};