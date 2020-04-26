/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,char color){
        if(i>=board.size()||i<0) return;
        if(j>=board[0].size()||j<0) return;

        if(board[i][j] == 'O'){
            board[i][j] = color;
            dfs(board,i+1,j,color);
            dfs(board,i-1,j,color);
            dfs(board,i,j+1,color);
            dfs(board,i,j-1,color);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int xlimit = board.size();
        int ylimit = board[0].size();
        for(int i = 0; i < xlimit;++i){
            for(int j = 0; j < ylimit;++j){
                if(board[i][j]=='O'&&(i==0||j==0||i==xlimit-1||j==ylimit-1)){
                    dfs(board,i,j,'G');
                }
            }
        }

        for(int i = 0; i < xlimit;++i){
            for(int j = 0; j < ylimit;++j){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='G')
                    board[i][j]='O';
            }
        }
    }
};
