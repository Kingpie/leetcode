/*
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//before optimized
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size()/2];

        int sum = 0;
        for(auto t:nums){
            sum += abs(mid-t);
        }
        return sum;
    }
};