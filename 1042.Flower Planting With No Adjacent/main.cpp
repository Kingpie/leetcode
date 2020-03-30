/*You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flower-planting-with-no-adjacent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> Adj[N];
        for(int i = 0; i < paths.size();++i){
            Adj[paths[i][0]-1].push_back(paths[i][1]-1);
            Adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }

        vector<int> flower(N,0);
        for(int i = 0; i < N; ++i){
            set<int> s = {1,2,3,4};
            for(int k = 0; k < Adj[i].size();++k){
                s.erase(flower[Adj[i][k]]);
            }
            flower[i] = *s.begin();
        }
        return flower;
    }
};

