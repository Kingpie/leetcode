/*You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jewels-and-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<int,int> diamond;
        for(auto t : J){
            diamond[t] = 0;
        }

        int count = 0;
        for(auto t : S){
            if(diamond.find(t) != diamond.end())
                ++count;
        }
        return count;
    }
};
solution.cpp: In member function dfs
Line 22: Char 32: error: invalid types ‘<unresolved overloaded function type>[int]’ for array subscript
import += dfs[subid];
^