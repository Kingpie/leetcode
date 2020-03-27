/*Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//slide window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.size();
        int left=0,right=0,maxCount=0,maxLen = 0;
        unordered_map<char,int> unique;
        while(right < len){
            if(!unique.count(s[right])){
                maxCount++;
            }
            unique[s[right]]++;

            while(maxCount > k){
                if(unique[s[left]]==1){
                    maxCount--;
                    unique.erase(s[left]);
                }else{
                    unique[s[left]]--;
                }
                left++;
            }

            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

