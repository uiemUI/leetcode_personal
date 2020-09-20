#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    static int kthGrammar(int N, int K)
    {
        if (N == 1)
            return 0;
        return (~K & 1) ^ kthGrammar(N - 1, (K + 1) / 2);
    }
};
class Solution2
{
public:
    static int kthGrammar(int N,int K)
    {
        if(N==1)
            return 0;
        if(K<=(1<<N-2)) //K在前一半，则在n-1行中，K的位置不变
            return kthGrammar(N - 1, K);
        else
            return kthGrammar(N - 1, K - (1 << N - 2)) ^ 1;

    }
};
int main(int argc, char const *argv[])
{
    int N, K;
    if(!(cin >> N >> K))
    {
        cerr << "error! input" << endl;
        exit(0);
    };
    cout << Solution2::kthGrammar(N, K) << endl;
    // N = 10;
    // cout.write((char*)&N, sizeof(int))<<endl;

    auto vecf = vector<float>{1., 2., 3., 4., 5.};
    cout.write((char*)vecf.data(), vecf.size() * sizeof(float)) << endl;
    
    const char *str = "http://c.biancheng.net/cplus/";
    cout.write(str, 4);
    return 0;
}
