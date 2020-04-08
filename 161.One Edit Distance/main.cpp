/*Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/one-edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size();
        int tlen = t.size();

        if(slen < tlen) return isOneEditDistance(t,s);

        if(slen - tlen > 1) return false;

        for(int i = 0; i < tlen;++i){
            if(s[i] != t[i]){
                if(slen == tlen){
                    return s.substr(i+1) == t.substr(i+1);
                }else{
                    return s.substr(i+1) == t.substr(i);
                }
            }
        }
        return slen == tlen+1;
    }
};

