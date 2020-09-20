#include"stand.h"

/*

28. 实现 strStr()
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
KMP算法，注意next为0的情况
*/
class Solution
{

    vector<int> getNext(const string &pat)
    {
        vector<int> next(pat.size());
        next[0] = 0; //pat的前后缀最长长度
        int i = 1;
        int j = 0;
        while (i < pat.size())
        {
            if (pat[i] == pat[j])
            {
                j++;
                next[i] = j;
                i++;
            }
            else
            {
                if(j!=0)
                    j = next[j - 1];
                else
                {
                    next[i] = 0;
                    i++;
                }
                
            }
        }
        return next;
    }

public:
    int strStr(string haystack, string needle)
    {
        //kmp算法
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        auto &&next = getNext(needle);
        int patLen = needle.size();
        int j = 0, i = 0;
        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                if (j == (patLen - 1))
                    return i-j;
                i++;
                j++;
            }
            else
            {   if(j!=0)
                    j = next[j - 1];
                else
                {
                    i++;
                }
                
            }
        }
        return -1;
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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}