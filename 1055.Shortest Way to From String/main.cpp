/*From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-way-to-form-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int shortestWay(string source, string target) {
        int tindex = 0;
        int sindex = 0;
        int count = 0;
        int lastTIndex = 0;
        while(sindex < source.size()){
            if(source[sindex] == target[tindex]){
                tindex++;
            }
            sindex++;

            if(sindex == source.size() && tindex != target.size()){
                if(lastTIndex == tindex)
                    return -1;

                count++;
                lastTIndex = tindex;
                sindex = 0;
            }
        }
        return count+1;
    }
};

