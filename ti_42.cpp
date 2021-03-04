/*
 * @Author: uiemUI
 * @Date: 2021-02-18 16:57:54
 * @LastEditTime: 2021-02-18 17:08:27
 * @LastEditors: uiemUI
 * @Description:接雨水
 * @FilePath: \leetcode_personal\ti_42.cpp
 */

 /**
  * @brief
  *42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 


思路 ，从单个元素考虑 选定索引为 Idx 的元素， idx位置上所能接的水 取决于其左侧 最大值 以及右侧最大值中的 最小值 -本身的值
由于 这大约是对称的，从左遍历，从右遍历都可以。用双指针 进行左右遍历， 若height[left] < height[right] 则可以认为 left处的两侧最大值中的小值位于左侧。
否则，right的处的 两侧最大值中的中最小值位于右侧。 
  */

#include"stand.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right = height.size()-1;
        int ans =0;
        int leftMax=0,rightMax=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                leftMax=max(leftMax,height[left]);
                ans+= (leftMax-height[left]);
                left++;
            }
            else
            {
                rightMax =max(rightMax,height[right]);
                ans+=(rightMax-height[right]);
                right--;
            }
            
        }

        return ans;

    }
};

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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}