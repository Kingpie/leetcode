/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//hash function
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> xset,yset;
        for(int i = 0; i < matrix.size();++i){
            for(int j = 0; j < matrix[0].size();++j){
                if(!matrix[i][j]){
                    xset.insert(i);
                    yset.insert(j);
                }
            }
        }

        for(int i = 0; i < matrix.size();++i){
            for(int j = 0; j < matrix[0].size();++j){
                if(xset.count(i)||yset.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};