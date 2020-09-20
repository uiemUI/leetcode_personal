/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

确定用穷状态自动 
输入: 空格,小数点，数字，+-符号，字符eE,其它字符
状态：起始的空格、符号位、整数部分、左侧有整数的小数点、左侧无整数的小数点、小数部分、字符e
*/

#include"stand.h"

class Solution
{
public:
    enum State
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E')
        {
            return CHAR_EXP;
        }
        else if (ch == '.')
        {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-')
        {
            return CHAR_SIGN;
        }
        else if (ch == ' ')
        {
            return CHAR_SPACE;
        }
        else
        {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s)
    {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {
                                {CHAR_SPACE, STATE_INITIAL},
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                {CHAR_SIGN, STATE_INT_SIGN},
                            }},
            {STATE_INT_SIGN, {
                                 {CHAR_NUMBER, STATE_INTEGER},
                                 {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                             }},
            {STATE_INTEGER, {
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_EXP, STATE_EXP},
                                {CHAR_POINT, STATE_POINT},
                                {CHAR_SPACE, STATE_END},
                            }},
            {STATE_POINT, {
                              {CHAR_NUMBER, STATE_FRACTION},
                              {CHAR_EXP, STATE_EXP},
                              {CHAR_SPACE, STATE_END},
                          }},
            {STATE_POINT_WITHOUT_INT, {
                                          {CHAR_NUMBER, STATE_FRACTION},
                                      }},
            {STATE_FRACTION, {
                                 {CHAR_NUMBER, STATE_FRACTION},
                                 {CHAR_EXP, STATE_EXP},
                                 {CHAR_SPACE, STATE_END},
                             }},
            {STATE_EXP, {
                            {CHAR_NUMBER, STATE_EXP_NUMBER},
                            {CHAR_SIGN, STATE_EXP_SIGN},
                        }},
            {STATE_EXP_SIGN, {
                                 {CHAR_NUMBER, STATE_EXP_NUMBER},
                             }},
            {STATE_EXP_NUMBER, {
                                   {CHAR_NUMBER, STATE_EXP_NUMBER},
                                   {CHAR_SPACE, STATE_END},
                               }},
            {STATE_END, {
                            {CHAR_SPACE, STATE_END},
                        }}};

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++)
        {
            CharType typ = toCharType(s[i]);
            if (transfer[st].count(typ) == 0)
            {
                return false;//非法输入
            }
            else
            {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }//注意end也是合法输入
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

        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}