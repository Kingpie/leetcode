/*Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


//quick sort
class Solution {
public:
    int partition(vector<int>& nums,int start,int end){
        int pivot = nums[start];
        while(start<end){
            while(start<end && nums[end]>pivot){
                end--;
            }
            nums[start] = nums[end];

            while(start<end && nums[start]<=pivot){
                start++;
            }

            nums[end] = nums[start];
        }
        nums[end] = pivot;
        return end;
    }

    void quickSort(vector<int>& nums,int start,int end){
        if(start < end){
            int pivot = partition(nums,start,end);
            quickSort(nums,start,pivot-1);
            quickSort(nums,pivot+1,end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};