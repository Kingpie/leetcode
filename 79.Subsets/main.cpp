/*Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
    void backtrace(vector<vector<int>>& ans, vector<int>& curr, int start, vector<int>& nums){
        ans.push_back(curr);

        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrace(ans, curr, i + 1, nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrace(ans, curr, 0, nums);
        return ans;
    }
};