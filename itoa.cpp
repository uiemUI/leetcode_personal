#include<vector>
#include<numeric>
#include<string>
#include<iostream>
#include"output_container.h"
using namespace std;


int main(int argc, char const *argv[])
{
    vector<float> vecf(10);
    std::iota(vecf.begin(), vecf.end(), 0.5);

    cout << vecf << endl;

    string word;
    word.clear();
    word.resize(5);
    std::iota(word.begin(), word.end(), 'a');
    cout << word << endl;
    vector<int> vecin;
    vecin.reserve(5);
    cout << vecin.size();
    cout << vecin.empty() << endl;
    for (int i = 0; i < 5;++i)
        vecin.emplace_back(i);
    vecin.pop_back();
    cout << vecin << endl;
    

    return 0;
}
