#include"stand.h"

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if(s.empty())
            return s;
        auto pstr = s;
        reverse(pstr.begin(), pstr.end());
        auto rStr = s + '#' + pstr;
        


        int next[rStr.size()] = {0}; 
        next[0] = 0;
        int len = 0;
        int i = 1;//从1开始
        while(i<rStr.size())
        {
            if(rStr[i]==rStr[len])
            {
                len++;
                next[i] = len;
                i++;//到下一个
            }
            else
            {
                if(len==0)
                    {
                        next[i] = 0;//回退到头
                        i++;
                    }
                else
                    len = next[len - 1];//当前不匹配，回退到前一个值(前一个是匹配的前后缀最长公共长度
            }
            //KMP
        }
        auto maxLen = next[rStr.size() - 1];//整个的最长公共前后缀
        auto sp = pstr.substr(0, pstr.size() - maxLen);
        return sp + s;

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

        string ret = Solution().shortestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}