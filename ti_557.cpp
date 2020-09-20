#include"stand.h"
/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.empty())
            return s;
        s += ' ';//先加上在取迭代器，不然会因为动态行为导致迭代器失效
        auto iter1 = s.begin();
        auto iter2 = s.begin();
       
        while (iter2 != s.end() && iter1 != s.end())
        {
            iter2 = find(iter1, s.end(), ' '); //找到' '的位置
            if (iter2 == s.end())
            {
                s.pop_back(); //没有找到' '
                return s;
            }
            reverse(iter1, iter2);
            iter1 = iter2 + 1; //更新位置
        }
        s.pop_back(); //删去前面加入的' '
        return s;
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

        string ret = Solution().reverseWords(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}