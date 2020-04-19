/*For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int len = A.size();
        int idx = len-1;
        int num = 0,flag=0,sum=0;
        vector<int> ans;
        while(idx>=0 || K || flag){
            num = idx>=0?A[idx]:0;
            sum = num+K%10+flag;
            if(sum>9){
                sum=sum%10;
                flag = 1;
            }else{
                flag = 0;
            }
            K /= 10;
            idx--;

            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

