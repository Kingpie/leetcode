/*Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


class Solution {
public:
    struct valueNum {
        int cnt = 0;
        int firstIdx = -1;
        int length = 0;
    };
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, valueNum> hashMap;
        int len = nums.size();
        int shortestLen = len;
        int maxCnt = 0;
        for (int i = 0; i < len; i++) {
            hashMap[nums[i]].cnt++;
            if (hashMap[nums[i]].firstIdx == -1) {
                hashMap[nums[i]].firstIdx = i;
            }
            hashMap[nums[i]].length = i - hashMap[nums[i]].firstIdx + 1;

            if (maxCnt < hashMap[nums[i]].cnt) {
                maxCnt = hashMap[nums[i]].cnt;
                shortestLen = hashMap[nums[i]].length;
            } else if (maxCnt == hashMap[nums[i]].cnt) {
                shortestLen = min(shortestLen, hashMap[nums[i]].length);
            } else {
                continue;
            }
        }

        return shortestLen;
    }
};
