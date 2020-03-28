/*Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 

Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/short-encoding-of-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//hash
class SolutionHash {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        for(int i = 0; i < words.size();++i){
            for(int j = 1;j<words[i].size();++j){
                s.erase(words[i].substr(j));
            }
        }

        int len = 0;
        for(auto t:s){
            len += t.length()+1;
        }
        return len;
    }
};
////////////////////////////////////////////////////////////
//trie
class TrieNode{
public:
    vector<TrieNode*> child = vector<TrieNode*>(26,NULL);
    int count = 0;

    TrieNode* insert(char letter){
        if(child[letter-'a'] == NULL){
            child[letter-'a'] = new TrieNode();
            count++;
            return child[letter-'a'];
        }
        return child[letter-'a'];
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<TrieNode*,int> m;
        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size();++i){
            auto cur = root;
            for(int j = words[i].size()-1; j >= 0; j--){
                cur = cur->insert(words[i][j]);
            }
            m[cur] = i;
        }

        int cnt = 0;
        for(auto &[ptr,idx]:m){
            if(ptr->count == 0){
                cnt += words[idx].length()+1;
            }
        }
        return cnt;
    }
};
