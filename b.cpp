#include <iostream>
#include<string>
#include<sstream>
#include<vector>
//#include<boost/format.hpp>
using namespace std;
int main() {
    // int a,b;
    // while(cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    //     cout << a+b << endl;
    string ss="12345";
    auto s2 =ss.substr(3);
    string ssr = "12 34 56 78";
    stringstream sss;
    sss.str(ssr);
    string temp;
    while(sss>>temp)
    {
        cout<<temp<<" \n";
    }

    vector<string> ves;
    cout<<s2<<endl;
    sss.clear();
    string abss="ab.cd.rfg.sssg.fsa";
    sss.str(abss);
    while(getline(sss,temp,'.'))
    {
        ves.emplace_back(std::move(temp));
    }//分割字符串
    //cout<<temp<<endl;
    cout<<"{";
    for(auto & item:ves)
        cout<<item<<" ";
    cout<<"}"<<endl;
    stringstream datastream("2020-08-07");
    vector<int> datas;
    for(string i;getline(datastream,i,'-');)//读到‘-’为止
    {
        datas.emplace_back(stoi(i));
        
    }
    for(const auto& item:datas)
        cout<<item<<"  ";
    cout<<endl;
    datastream.clear();
    datastream.str("atx_sf.cpp");
    datastream.ignore(INT_MAX,'.');//忽略其他字符直到第一个.
    string filetye;
    datastream>>filetye;
    cout<<filetye<<endl;
    //cout<< boost::format("%2% \n %1% \n %3%" )%"first"%"second"%"third";
    

    

    //cout<<endl;



  
 
}                                    