/*Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0,end = 0,len=nums.size(),sum=0,minLen=INT_MAX;
        while(end<len){
            sum += nums[end];
            while(sum >= s){
                minLen = min(minLen,end-start+1);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        return minLen == INT_MAX?0:minLen;
    }
};
