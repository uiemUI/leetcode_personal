#include"stand.h"



int main(int argc, char const *argv[])
{

    fstream outfile;
    outfile.open("ss.txt", ios::out|ios::in | ios::trunc);
    outfile << "test outputfile" ;
    vector<int> avect;
    avect = vector<int>(10, 0);
    for(auto I:avect)
    {
        std::cout << I;
    }

    return 0;
}
