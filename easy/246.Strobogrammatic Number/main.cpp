/*A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strobogrammatic-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> m = {{'1','1'},{'6','9'},{'9','6'},{'8','8'},{'0','0'}};
        int len = num.size();
        for(auto i = 0; i < len; ++i){
            auto it = m.find(num[i]);
            if(it == m.end())
                return false;
            if(num[len-i-1] != m[num[i]])
                return false;
        }
        return true;
    }
};

