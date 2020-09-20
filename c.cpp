#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int  func(int x,vector<int>& vec)
{
    
   
    while(x>vec.back())
    {
        vec.push_back((vec.back() + 1) / 2 + vec.back());
    }
    if (std::find(vec.begin(), vec.end(), x) == vec.end())
        //不在vector,说明符合要求
        return 1;
    else
        return 0;
    

}
int main(int argc, char const *argv[])
{
    vector<int> vec;
    vec.push_back(2);
 

    int t , ans = 0;
    cin >> t; //t 轮（
    while(t--)
    {
        int n;
        cin >> n;
        ans += func(n, vec);
    }

    std::cout << ans << std::endl;
    return 0;
}
