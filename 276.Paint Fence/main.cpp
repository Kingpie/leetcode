/*There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Example:

Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

            post1  post2  post3
 -----      -----  -----  -----
   1         c1     c1     c2
   2         c1     c2     c1
   3         c1     c2     c2
   4         c2     c1     c1 
   5         c2     c1     c2
   6         c2     c2     c1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-fence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int numWays(int n, int k) {
        if(n<=1) return n*k;
        int dp1 = k;
        int dp2 = k*k;

        for(int i = 2; i < n; ++i){
            int temp = dp2;
            dp2 = (dp1+dp2)*(k-1);
            dp1 = temp;
        }
        return dp2;
    }
};

