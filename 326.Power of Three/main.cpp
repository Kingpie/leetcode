/*Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//loop
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        while(n%3==0){
            n /= 3;
        }
        return n == 1;
    }
};

//log
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double res = log10(n)/log10(3);
        return res -int(res) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
    }
};