#include<vector>
#include<iostream>
#include<valarray>
#include"output_container.h"
#include"stand.h"
using std::cout;
using std::endl;

template<typename T>
std::ostream& operator<<(std::ostream& out,const std::valarray<T>& valar)
{
    for(auto val: valar)
        out << val << "\n";
    return out;
}

// template <typename Container>
// std::ostream &operator<<(std::ostream &out, const Container &valar)
// {
// //     for (auto val : valar)
// //         out << val << "\n";
// //     return out;
// // }
//     for (auto be = valar.begin(); be != valar.end();++be)
//     {
//         out << *be << '\n';

//     }
//     return out;
// }

int main(int argc, char const *argv[])
{
    double pi = 3.14159265359;

    std::valarray<double> val{1., 2., 3., 4., 5.};
    std::cout << val.size() << endl;
    val = val * pi;
    std::cout << val << endl;
    val= cos(val);
    cout << val << endl;
    std::vector<int> vecin{1, 3, 4, 5, 6, 9};
    //vecin = cos(std::valarray<int>(vecin.data()))
    int a[] = {1, 2, 3, 4};
    std::valarray<int> vala{a,4};
    auto vecda = vecin.data();
    std::vector<int> mx(vecda,vecda+vecin.size());
    //std::valarray<int> valin{vecda, vecda + vecin.size()};
    cout << mx<< endl;

    vector vec(10, 0);//自动模板推导
    tuple tu(2, 3.0f);
    //shared_ptr ptr=new int[10];
   




    return 0;
}

