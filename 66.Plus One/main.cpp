/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//defend double 100% players
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; --i){
            if(digits[i] < 9){
                ++digits[i];
                return digits;
            }
            if(i == 0){
                digits[i] = 1;
                digits.push_back(0);
            }
            else
                digits[i] = 0;
        }
        return digits;
    }
};