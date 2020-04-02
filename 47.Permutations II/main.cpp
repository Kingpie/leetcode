/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    void dfs(int depth,vector<int>& nums,vector<int>& flag,vector<int>& path,vector<vector<int>>& res){
        if(depth == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(!flag[i]){
                if(i > 0 && nums[i] == nums[i-1] && !flag[i-1])
                    continue;

                path.push_back(nums[i]);
                flag[i] = 1;
                dfs(depth+1,nums,flag,path,res);
                flag[i] = 0;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> flag(nums.size(),0);
        vector<int> path;
        dfs(0,nums,flag,path,res);
        return res;
    }
};