#include"stand.h"

/*
*696 计数二进制子串
*

给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr=0,n=s.size(),last=0,ans=0;
        while(ptr<n)
        {
            auto c=s[ptr];//每次循环第一个字符
            int count =0;
            while (ptr<n&&s[ptr]==c)//都是同一个字符
            {
                ++count;
                ++ptr;
            }
            ans+=min(last,count);
            last=count;
        }
        return ans;
    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().countBinarySubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
