/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

//force
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto len = nums.size();
        for (int i = 0; i < len; ++i) {
            for(int j = i+1;j<len;++j){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {};
    }
};

//hash
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(auto i = 0; i < nums.size();++i){
            if (m.find(target-nums[i]) != m.end()){
                return {m[target-nums[i]],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};