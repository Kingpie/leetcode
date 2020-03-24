/*Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        unordered_map<string,int> s;
        int min = 2000;

        for(auto t = 0; t < list1.size();++t){
            s[list1[t]] = t;
        }

        for(auto i = 0; i < list2.size(); ++i){
            auto it = s.find(list2[i]);
            if(s.find(list2[i]) != s.end())
            {
                if(it->second + i < min){
                    min = it->second+i;
                    result.clear();
                    result.push_back(list2[i]);
                }else if(it->second + i == min){
                    result.push_back(list2[i]);
                }
            }
        }

        return result;
    }
};
