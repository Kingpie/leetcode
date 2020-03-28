/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//slide window before optimized
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,maxLen=0,duplicate = 0;
        unordered_set<char> unique;
        while(right<s.size()){
            if(!unique.count(s[right])){
                unique.insert(s[right]);
            }
            else
                duplicate++;

            while(duplicate>0){
                if(s[left] == s[right]){
                    duplicate--;
                }else{
                    unique.erase(s[left]);
                }
                left++;
            }

            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};