/*
 On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/available-captures-for-rook
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt = 0,rx = -1,ry=-1;
        int dx[4] ={0,-1,0,1};
        int dy[4] = {1,0,-1,0};
        for(int i = 0;i<8;++i){
            for(int j = 0;j<8;++j){
                if(board[i][j]=='R'){
                    rx = i;
                    ry = j;
                    break;
                }
            }
        }

        for(int i = 0; i < 4;++i){
            for (int step = 0;; ++step) {
                int tx = rx + step * dx[i];
                int ty = ry + step * dy[i];
                if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
                if (board[tx][ty] == 'p') {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};