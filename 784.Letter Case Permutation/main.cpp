/*Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
    vector<string> ans;
public:
    char getNewLetter(char a){
        if(a>='a'&&a<='z'){
            return a-('a'-'A');
        }else if(a>='A'&&a<='Z'){
            return a+('a'-'A');
        }else return a;
    }

    void backtrace(string& s,int i){
        if(i == s.size()){
            ans.push_back(s);
            return;
        }

        backtrace(s,i+1);
        char letter = getNewLetter(s[i]);
        if(letter != s[i]){
            s[i]=letter;
            backtrace(s,i+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        backtrace(S,0);
        return ans;
    }
};