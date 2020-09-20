#include"stand.h"

/*
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，
编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
例
 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
*/
class Solution {
    static constexpr int mod = 1000000007;
    static constexpr int coins[4] = {1,5,10,25};
public:
    int waysToChange(int n) {
        vector<int> f(n+1,0);
        f[0]=1;
        for(int c=0;c<4;++c)
        {
            auto coin = coins[c];
            for(int i=coin;i<=n;++i)
            {
                f[i]=(f[i]+f[i-coin])%mod;
            }
        }
        return f[n];
    }
};

int stringToInteger(string input) {
    return stoi(input );
}

int  main() {
    string line;
     while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().waysToChange(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}