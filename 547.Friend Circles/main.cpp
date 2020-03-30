/*There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-circles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//union and find
class Solution {
private:
    vector<int> parent;
    vector<int> len;
    int count = 0;
public:
    int find(int x){
        while(x!=parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void bond(int x,int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return;
        if(len[rootx]>len[rooty]){
            parent[rooty] = rootx;
            len[rootx] += len[rooty];
        }else{
            parent[rootx] = rooty;
            len[rooty] += len[rootx];
        }
        count--;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        for(int i = 0; i < M.size();++i){
            parent.push_back(i);
            len.push_back(1);
            count++;
        }

        for(int i = 0; i < M.size();++i){
            for(int j = 0; j < M[0].size();++j){
                if(i!=j&&M[i][j]){
                    bond(i,j);
                }
            }
        }
        return count;
    }
};

//dfs
class Solution {
public:
    void dfs(int index,vector<int>& visited,vector<vector<int>>& M){
        for(int i = 0; i < M.size(); ++i){
            if(M[i][index]==1 && visited[i]==0){
                visited[i]=1;
                dfs(i,visited,M);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        vector<int> visited(m,0);

        int cnt = 0;
        for(int i = 0; i < m;++i){
            if(visited[i]== 0){
                ++cnt;
                dfs(i,visited,M);
            }
        }
        return cnt;
    }
};

//bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        vector<int> visited(m,0);
        queue<int> q;

        int cnt = 0;
        for(int i = 0; i < m;++i){
            if(visited[i]==0){
                cnt++;
                q.push(i);
                while(!q.empty()){
                    auto point = q.front();
                    q.pop();
                    for(int j = 0; j < m;++j){
                        if(M[point][j] && visited[j] != 1){
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};