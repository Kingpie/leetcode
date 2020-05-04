/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(),end=0,step=0;
        int maxPos = 0;
        for(int i = 0; i < len-1;++i){
            if(maxPos>=i){
                maxPos = max(maxPos,i+nums[i]);
                if(i==end){
                    step++;
                    end=maxPos;
                }
            }
        }
        return step;
    }
};
