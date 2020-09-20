
/*34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

*/
#include"stand.h"

class Solution
{
private:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(); //左开右闭区间
        while (left < right)
        {
            int mid = (left + right)>>1; //取中值
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid; //缩小范围
        }
        return left; //此时left==right
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        int a = search(nums, target), b = search(nums, target + 1); //search(nums,target)，返回nums中>=target的第一个索引，即左边界
        if (a == nums.size() || nums[a] != target)
            return {-1, -1};
        else
            return {a, b - 1};
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch); //find_if 找到第一个空格的迭代器，删去空白符号
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch); 
                }).base(), //rbegin反向迭代器，base返回反向迭代器的底层迭代器
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2); //第二个参数是count是子串的长度
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

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}