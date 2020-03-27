/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

 Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> total;
        for(int i = 1; i <= numRows; ++i){
            vector<int> v(i,1);
            for(int j = 0; j < v.size(); ++j){
                if(j != 0 && j != v.size()-1){
                    v[j] = total[i-2][j-1]+total[i-2][j];
                }
            }
            total.push_back(v);
        }
        return total;
    }
};
