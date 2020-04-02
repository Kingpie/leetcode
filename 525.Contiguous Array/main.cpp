/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 0;
        unordered_map<int,int> m{{0,0}};

        int sum = 0;
        for(int i = 0; i < len; ++i){
            if(nums[i]){
                sum++;
            }else{
                sum--;
            }

            if(m.count(sum)){
                maxLen = max(maxLen,i-m[sum]+1);
            }else{
                m[sum] = i+1;
            }
        }
        return maxLen;
    }
};