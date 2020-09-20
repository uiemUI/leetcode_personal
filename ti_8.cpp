
/*// 8. 字符串转换整数(atoi)
//     请你来实现一个 atoi 函数，使其能将字符串转换成整数。

//     首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

//     如果第一个非空字符为正或者负号时，
//则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。 假如第一个非空字符是数字，
则直接将其与之后连续的数字字符组合起来，形成一个整数。 该字符串在有效的整数部分之后也可能会存在多余的字符，
那么这些字符可以被忽略，它们对函数不应该造成影响。 
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

//     在任何情况下，若函数不能进行有效的转换时，请返回 0 。

//     提示：

//     本题中的空白字符只包括空格字符 ' ' 。
 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为[−231, 231 − 1]。
 如果数值超过这个范围，请返回 INT_MAX(231 − 1) 或 INT_MIN(−231) 。

*/
#include "stand.h"
class Automaton
{
    enum State
    { START,SIGNED,IN_NUMBER,END};

    State state = START;
    unordered_map<State, vector<State>> table{
        {START, {START, SIGNED, IN_NUMBER, END}},
        {SIGNED, {END, END, IN_NUMBER, END}},
        {IN_NUMBER, {END, END, IN_NUMBER, END}},
        {END, {END, END, END, END}}
        };

    int get_col(char c)
        {
            if(isspace(c))
                return 0;
            if(c=='+'||c=='-')
                return 1;
            if(isdigit(c))
                return 2;
            return 3;
        }
    public:
        int sign = 1;
        int64_t ans = 0;
        void get(char c)
        {
            state = table[state][get_col(c)];
            if(state == IN_NUMBER)
            {
                ans = ans * 10 + c - '0';
                ans = sign == 1 ? min(ans, (int64_t)INT_MAX) : min(ans, -(int64_t)INT_MIN);
            }
            else if (state == SIGNED)
                sign = c == '+' ? 1 : -1;
        }
        bool isEnd()
        {
            return state == END;
        }
};

class Solution
{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for( char c:str)
        {
            automaton.get(c);
            if(automaton.isEnd())
                break;
        }
        return automaton.sign * automaton.ans;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}