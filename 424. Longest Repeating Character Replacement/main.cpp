/*Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
 

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//slide window
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letter(26,0);
        int len = s.size();
        int left = 0,right = 0,maxCount = 0,maxLen = 0;
        while(right < len){
            letter[s[right]- 'A']++;
            maxCount = max(maxCount,letter[s[right]-'A']);

            if(right-left+1>maxCount+k){
                letter[s[left++]-'A']--;
            }

            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};
