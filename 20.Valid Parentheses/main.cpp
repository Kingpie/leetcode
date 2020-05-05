/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m = {{')','('},{'}','{'},{']','['}};
        if((s.size()&1)==1) return false;
        stack<char> stk;
        for(int i = 0; i < s.size();++i){
            if(m.count(s[i])){
                if(stk.empty()){
                    return false;
                }else{
                    if(m[s[i]]==stk.top()){
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }else{
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};