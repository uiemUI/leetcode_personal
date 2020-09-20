#include"stand.h"

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
private:
    bool isPair(char left,char right)
    {
        if ((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}'))
            return true;
        else
            return false;
    }

public:

    bool isValid(string s)
    {
        stack<char> stackChar;
        if(s.empty())
            return true;
        int n = s.size();
        for (int i = 0; i < n;++i)
        {
            char temp = s[i];
            if (temp == '(' || temp == '[' || temp == '{')
                stackChar.push(temp);
            if (temp == ')' || temp == ']' || temp == '}')
            {
                if(stackChar.empty())
                    return false;
                if(isPair(stackChar.top(),temp))

                    stackChar.pop();
                else
                    return false;
                
                
            }
            
        }
        if(stackChar.empty())
            return true;
        else
            return false;
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

        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    

    return 0;
}
