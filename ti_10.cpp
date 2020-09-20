#include"stand.h"

// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

//     '.' 匹配任意单个字符 '*' 匹配零个或多个前面的那一个元素
//         所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

//     说明 :

//     s 可能为空，且只包含从 a -
//     z 的小写字母。 p 可能为空，且只包含从 a - z 的小写字母，以及字符 . 和 *。 示例 1 :

//     来源：力扣（LeetCode） 链接：https : //leetcode-cn.com/problems/regular-expression-matching
//                                          著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{



public:
    bool isMatch(string s, string p)
    {
        const int sLen = s.size();
         const int pLen   = p.size();

        bool dp[sLen + 1][pLen];

        dp[0][0] = 1;
        for (int j = 2; j <= pLen;++j)
        {
            dp[0][j] = dp[0][j - 2] && (p[j - 1] == '*');//第一个字符，p第j个字符为'*
        }
        for (int i=1;i<=sLen;++i)
        {
            for (int j = 1; j <= pLen;j++)
            {
                int m = i - 1, n = j - 1;
                if(p[n]=='*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] &&
                                                   (s[m] == p[n - 1] || p[n - 1] == '.'));
                }
                else if(s[m]==p[n-1]||p[n-1]=='.')
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[sLen][pLen];
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        
        cout << out << endl;
    }
    return 0;
}