#include "stand.h"
/*剑指 Offer 33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

 

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true

这种要减一的乖乖两边闭吧
 */
class Solution
{
private:
    bool verifyPostorder(vector<int> &postorder, int begin, int end) //两边都是闭区间
    {
        if (begin >= end)
            return true;
        
        

        int root = postorder[end];
        int i = begin;
        for (; i < end; i++)
        {
            if (postorder[i] > root)
                break; //此时i为左右子树的分界线
        }
        //判断右边是否是右子树
        int j = i;
        for (; j < end; j++)
        {
            if (postorder[j] < root)
                return false;
        }
        bool left = true;
        
        left = verifyPostorder(postorder, begin, i-1);
        bool right = true;
        right = verifyPostorder(postorder, i, end - 1);
        return left && right;
    }

public:
    bool verifyPostorder(vector<int> &postorder)
    {
        if (postorder.empty())
            return false;
        return verifyPostorder(postorder, 0, postorder.size()-1);
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> postorder = stringToIntegerVector(line);

        bool ret = Solution().verifyPostorder(postorder);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}