/*Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        int minNum = INT_MAX;
        for(int i = 0; i < len; ++i){
            minNum = min(minNum,nums[i]);
        }
        for(int i = len-1; i >=0; --i)
            sum += nums[i]-minNum;
        return sum;
    }
};

