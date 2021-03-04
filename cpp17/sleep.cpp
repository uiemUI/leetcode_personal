#include<iostream>
#include<chrono>
#include<thread>

int main(int argc, char const *argv[])
{
    /* code */
    using namespace std;
    using namespace chrono_literals;//字面值常量
    cout<<" the max threads that the machine supports is "<<thread::hardware_concurrency()<<" \n";
    cout<<" Going to sleep for 5 seconds and 300 milli second .\n";
    this_thread::sleep_for(5s+300ms);
    cout<<"Going to sleep for another 3 seconds.\n";
    this_thread::sleep_until(chrono::high_resolution_clock::now()+3s);
    cout<<"That's it.\n"<<endl;
    return 0;
}
