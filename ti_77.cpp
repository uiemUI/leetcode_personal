#include"stand.h"
// 77. 组合
//     给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

//     示例 :

//     输入 : n = 4,
//            k = 2 输出 : [
//                [ 2, 4 ],
//                [ 3, 4 ],
//                [ 2, 3 ],
//                [ 1, 2 ],
//                [ 1, 3 ],
//                [ 1, 4 ],
//            ] class Solution
// {
#include"output_container.h"

class Solution
{
private:
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> temp;
        temp.reserve(k);
        //function<void(int)>
        function<void(int)>  dfs = [&](int cur) {
            if (temp.size() == k)
            {
                res.emplace_back(temp);
                return;
            }

            if (cur > n)
                return;
            if (((n - cur + 1) + temp.size()) < k)
                return;
            temp.emplace_back(cur);
            dfs(cur + 1);
            temp.pop_back();
            dfs(cur + 1);
        };
        dfs(1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n, k;
    while(cin>>n && cin>>k)
    {
        auto res(Solution().combine(n, k));
        cout << res << endl;
    }
    return 0;
}
