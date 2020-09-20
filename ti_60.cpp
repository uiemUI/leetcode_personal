#include "stand.h"

class Solution
{
private:
    template <typename T>
    auto idxToValue(list<T>& listVs,int idx)->decltype(listVs.begin())
    {
        auto listVsB = listVs.begin();

        for (int i = 0; i < idx; i++)
        {
            listVsB++;
        }
        return listVsB;
    }
public:
    string getPermutation(int n, int k)
    {
        // // 注意：相当于在 n 个数字的全排列中找到下标为 k - 1 的那个数，因此 k 先减 1
        k--;
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n;i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        list<char> nums(n);

        std::iota(nums.begin(), nums.end(), '1');
        string res;
        res.reserve(n);
       
        for (int i = n - 1; i >= 0;i--)
        {
            int idx = k/factorial[i];
            auto valIt = idxToValue(nums, idx);
            res.push_back(*valIt);
            nums.erase(valIt);
            k -= idx * factorial[i];

        }
        return res;
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
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    
    }
    return 0;
}