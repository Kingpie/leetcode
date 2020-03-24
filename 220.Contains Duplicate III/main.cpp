/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty()) return false;
        set<long> st;
        for (int i = 0; i < nums.size(); ++i) {
            auto s = st.lower_bound((long)nums[i] - t);//找大于等于num[i] - t的数
            if (s != st.end() && *s <= (long)nums[i] + t) return true;//如果找到并且这个数小于等于nums[i] + t，返回true
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};