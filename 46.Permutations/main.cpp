/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//backtrace
class Solution {
public:
    void dfs(vector<int>& nums,int depth,vector<int>& flag,vector<int>& path,vector<vector<int>>&res){
        if(depth == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size();++i){
            if(!flag[i]){
                flag[i] =1;
                path[depth] = nums[i];
                dfs(nums,depth+1,flag,path,res);
                flag[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> flag(nums.size(),0);
        vector<int> path(nums.size());

        dfs(nums,0,flag,path,res);
        return res;
    }
};
