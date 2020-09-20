/*
使用chrono
*/
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include <ctime>
#include"timerxx.h"
using std::cout;
using std::endl;
using namespace std::chrono;

void fun()
{
    cout << "hello world" << endl;
}
int main(int argc, char const *argv[])
{
    std::chrono::minutes t1(10); //10分钟
    std::chrono::seconds t2(300); //300 seconds
    auto t3 = t1 - t2;
    std::chrono::minutes tmin3 = std::chrono::duration_cast<std::chrono::minutes>(t3); //单位转换
    std::chrono::milliseconds tm3(t3); //或者构造
    cout << t3.count() <<" seconds"<< endl;
    cout << tmin3.count() << " minutes" << endl;
    cout << tm3.count() << " miliseconds" << endl;

    system_clock::time_point now = system_clock::now();
    std::time_t last = system_clock::to_time_t(now - hours(24));//前一天的时间
    std::time_t next = system_clock::to_time_t(now + hours(24));
    cout << "last " << last << endl;
    auto lasttime = std::put_time(std::localtime(&last), "%a  %c");
    //cout << lasttime._M_tmb << endl;
    cout << lasttime << endl;
    cout << now.time_since_epoch().count() << endl; //从1970.1.1到现在的时间
    cout << "One day ago the time was " 
         << std::put_time(std::localtime(&last), "%a %c") << endl;

    cout << "the next day the time is "
         << std::put_time(std::localtime(&next), "%A %c") << endl; //时间的格式化

    auto t = system_clock::to_time_t(system_clock::now());
    cout << std::put_time(std::localtime(&t), "%Y-%m-%d:: %X") << endl;

    auto time_begin = std::chrono::high_resolution_clock::now();
    fun();
    cout << "func() 测试用时： " 
        << duration_cast<microseconds>(std::chrono::high_resolution_clock::now() - time_begin).count()
         << "微秒"
         << endl;

    Timer timerr ;
    fun();
    cout << "func()测试用时： " << timerr.elapsed_micro()<< "微秒" << endl;

    return 0;
}
