/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/game-of-life
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0) return;
        vector<vector<int>> result = board;
        vector<vector<int>> direct = {{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};

        int xlimit = board.size();
        int ylimit = board[0].size();
        for(int x = 0; x < xlimit;++x){
            for(int y = 0; y < ylimit;++y){
                int sum = 0;
                for(int i = 0; i < 8;++i){
                    int newx = x+direct[i][0];
                    int newy = y+direct[i][1];
                    if(newx>=0&&newx<xlimit&&newy>=0&&newy<ylimit){
                        if(board[newx][newy])
                            sum++;
                    }
                }

                if(board[x][y]){
                    if(sum<2 || sum>3){
                        result[x][y]=0;
                    }
                }else{
                    if(sum == 3){
                        result[x][y]=1;
                    }
                }
            }
        }
        board = result;
    }
};