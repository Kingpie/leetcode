/*Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
Example 2:

Input: "aeiou"
Output: ""
 

Note:

S consists of lowercase English letters only.
1 <= S.length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-vowels-from-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        for(auto it = S.begin(); it != S.end();++it){
            if(vowel.count(*it)){
                S.erase(it);
                it--;
            }
        }
        return S;
    }
};

