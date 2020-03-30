/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size()-1;
        unordered_set<char> unique = {'a','e','i','o','u','A','E','I','O','U'};
        while(start < end){
            while(start<end && !unique.count(s[start])){
                start++;
            }

            while(start<end && !unique.count(s[end])){
                end--;
            }

            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            start++;
            end--;
        }
        return s;
    }
};

