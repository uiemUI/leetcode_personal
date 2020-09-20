#include"stand.h"

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int nLen = nums.size();
        if (nLen == 0)
            return false;
        vector<vector<vector<int>>> dp(nLen, vector<vector<int>>(nLen, vector<int>(2, 0)));
        for (int i = 0; i < nLen; i++)
        {
            dp[i][i][0] = nums[i];
        }
        //斜着遍历
        for (int it = 1; it < nLen; it++)
        {
            for (int i = 0; i < nLen - it; i++)
            {
                int j = i + it;
                int left = nums[i] + dp[i + 1][j][1];
                int right = nums[j] + dp[i][j - 1][1];
                if (left > right)
                {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                }
                else
                {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                }
            }
        }
        return dp[0][nLen - 1][0] > dp[0][nLen-1][1];
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
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().PredictTheWinner(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

