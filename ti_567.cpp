/*
567. Permutation in String
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.

*/

#include"stand.h"
    class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        //s2's permutation requires that the size of s2 equals the size of s2's substring
        unordered_map<char, int> needs, windows;
        for (char c : s1)
            needs[c]++;
        int valid = 0;
        int left = 0, right = 0;
        while (right < s2.size())
        {
            char c = s2[right];
            right++;
            if (needs.count(c))
            {
                windows[c]++;
                if (windows[c] == needs[c])
                    valid++;
            }
            while ((right - left) >= s1.size())
            {
                if (valid == needs.size() && (right - left) == s1.size())
                    return true;
                char d = s2[left]; //若符合条件，则d不应该在needs中
                left++;
                if (needs.count(d))
                {
                    if (windows[d] == needs[d])
                        valid--;
                    windows[d]--;
                }
            }
        }
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}