#include"stand.h"

/* 201. 数字范围按位与
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0
通过次数27,350*/

/*基本思路是找m和n的二进制公共前缀*/
// int main(int argc, char const *argv[])
// {
//     int mask = 1<<30;
//     //mask >>= 1;
//     std::cout << mask << std::endl;
//     bitset<32> bitset1{mask};
//     cout << bitset1 << endl;
//     cout << bitset<32>(mask >> 1) << endl;
//     return 0;
// }
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int mask = 1 << 30; //符号位是相同的，不需要对比
        int ans = 0;
        while (mask > 0 && (mask & m) == (mask & n))
        {
            ans |= m & mask;
            mask >>= 1;
        }
        return ans;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().rangeBitwiseAnd(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}