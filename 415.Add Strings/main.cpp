/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1= num1.size(),len2=num2.size();
        int idx1 = len1-1,idx2=len2-1;
        int n1=0,n2=0;
        string ans;
        int flag = 0;
        while(idx1>=0 || idx2>=0 || flag){
            n1=idx1>=0?num1[idx1]-'0':0;
            n2=idx2>=0?num2[idx2]-'0':0;
            int sum = n1+n2+flag;
            if(sum>9){
                sum=sum%10;
                flag=1;
            }else{
                flag=0;
            }
            ans.push_back(sum+'0');
            idx1--;
            idx2--;
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};