/*
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
Example:

Input: 3
Output: [1,3,3,1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int N = rowIndex;
        long pre = 1;
        ans.push_back(1);
        for (int k = 1; k <= N; k++) {
            long cur = pre * (N - k + 1) / k;
            ans.push_back((int) cur);
            pre = cur;
        }
        return ans;
    }
};
