// 76. 最小覆盖子串
//     给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。

//     示例：

//     输入：S = "ADOBECODEBANC",
//     T = "ABC" 输出： "BANC"

//     提示：

//     如果 S 中不存这样的子串，则返回空字符串 ""。 如果 S 中存在这样的子串，我们保证它是唯一的答案。

#include"stand.h"
    class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> needs, windows;
        for (char c : t)
            needs[c]++;
        int valid = 0;
        //needs中记录t中各个字符的出现次数，windows记录窗口中各个字符的次数
        //valid表示windows字符次数与needs中字符次数相等的情况，就是满足条件的字符值，当needs中每个字符都满足条件是，valid==needs.size()
        int len = INT_MAX;
        int start = 0;
        int left = 0, right = 0; //左开右闭
        while (right < s.size())
        {
            char c = s[right]; //将要加入windows中的字符
            right++;
            if (needs.count(c))
            {
                windows[c]++;
                if (windows[c] == needs[c])
                    valid++;
            }

            //
            while (valid == needs.size()) //该windows符合条件
            {
                if ((right - left) < len)
                {
                    len = right - left; //更新len
                    start = left;
                }
                char ctemp = s[left];
                left++;
                if (needs.count(ctemp))
                {
                    if (windows[ctemp] == needs[ctemp])
                        valid--;
                    windows[ctemp]--;
                }
            }
        }
        return len == INT_MAX ? " " : s.substr(start, len);
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}