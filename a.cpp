#include <iostream>
#include <cstdio>
#include<opencv2/core.hpp>
using namespace std;

int main()
{
    //freopen("1.in","r",stdin);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            ans += x;
        }
    }
    cout << ans << endl;
    auto image=cv::Mat();
    
    return 0;
}