/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
private:
    vector<int> parent;
    vector<int> len ;
    int count = 0;
public:
    int find(int x){
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void bond(int p,int q){
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq) return;

        if(len[rootp]>len[rootq]){
            parent[rootq] = rootp;
            len[rootp] += len[rootq];
        }else{
            parent[rootp] = rootq;
            len[rootq] += len[rootp];
        }
        count--;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        count = n;
        for(int i = 0; i < n; ++i){
            parent.push_back(i);
            len.push_back(1);
        }

        for(auto t:edges){
            bond(t[0],t[1]);
        }
        return count;
    }
};
