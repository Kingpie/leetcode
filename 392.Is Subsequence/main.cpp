/*Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class SolutionGreedy {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[idx] == t[i]) {
                idx++;
            }
        }
        return idx == s.size();
    }
};

class SolutionHash {
public:
    bool isSubsequence(string s, string t) {
        int size = t.size(), pre = -1;
        unordered_map<char, vector<int>> ump;
        for (int i = 0; i < size; ++i) ump[t[i]].push_back(i);
        for (auto c : s) {
            auto it = upper_bound(ump[c].begin(), ump[c].end(), pre);
            if (it == ump[c].end()) return false;
            pre = *it;
        }
        return true;
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();