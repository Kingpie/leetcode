/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


//force solution
class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        data = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; ++k)
            sum += data[k];
        return sum;
    }
};

//cache
class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        data.push_back(0);
        int sum = 0;
        for(int i = 0; i < nums.size();++i){
            sum += nums[i];
            data.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return data[j+1] - data[i];
    }
};