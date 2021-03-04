/*
 * @Author: uiemUI
 * @Date: 2021-02-21 19:51:43
 * @LastEditTime: 2021-02-21 20:27:55
 * @LastEditors: uiemUI
 * @Description:
 * @FilePath: \leetcode_personal\ti_31.cpp
 */

#include"stand.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

template<class BidirIt>
bool wnext_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false; // 没有元素 
    BidirIt i = last;
    if (first == --i) return false; // 只有一个元素， i变成最后一个元素。

    while (true) {
        BidirIt i1, i2;

        i1 = i;  // 
        if (*--i < *i1) { //  i1和 i是相邻的两个数，,找到小于 后继元素的 最右边的元素。这样的话，对于i1，其右边的数都是降序的。 
            i2 = last; // 再 从最右边遍历，
            while (!(*i < *--i2))
                ; // 找到比 i稍大的数
            std::iter_swap(i, i2); // 两数交换
            std::reverse(i1, last);// 对齐进行翻转， i1右边的数变为 升序的。
            // std::sort()
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
            
        }
    }
}




void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}