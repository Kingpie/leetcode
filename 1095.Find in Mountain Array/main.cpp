/*(This problem is an interactive problem.)

You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 

Constraints:

3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-in-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray& mountainArr,int left,int right,int target,bool asc){
        while(left<=right){
            int mid = left+(right-left)/2;
            if(target == mountainArr.get(mid))
                return mid;

            if(mountainArr.get(mid)> target){
                left = asc?left:mid+1;
                right= asc?mid-1:right;
            }else{
                left = asc?mid+1:left;
                right= asc?right:mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0,right=mountainArr.length()-1;
        while(left+1<right){
            int mid = left+(right-left)/2;

            if(mountainArr.get(mid)>mountainArr.get(mid-1)){
                left = mid;
            }else{
                right = mid;
            }
        }
        int peakIdx = mountainArr.get(left) > mountainArr.get(right)? left: right;

        int leftIdx = binarySearch(mountainArr,0,peakIdx,target,true);
        return leftIdx!=-1?leftIdx:binarySearch(mountainArr,peakIdx+1,mountainArr.length()-1,target,false);
    }
};