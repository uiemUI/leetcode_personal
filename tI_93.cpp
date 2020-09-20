#include<string>
#include<iostream>
#include<sstream>
#include<istream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<assert.h>
#include<tuple>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        if (s.size()>12) return results;
        for(int i=1;i<s.size()&&i<=3;++i)
            for(int j=i;j<s.size()&&j<=i+3;++j)
                for(int k=j;k<s.size()&&k<=j+3;++k)
                { 
                    auto s1=s.substr(0, i);//[0,i)
                    auto s2=s.substr(i, j-i);//[i,j)
                    auto s3 =s.substr(j, k-j);//[j,k)
                    auto s4=s.substr(k);//[k,end)
                    if(isLegal(s1)&&isLegal(s2)&&isLegal(s3)&&isLegal(s4))
                    { 
                        string result=s1+"."+s2+"."+s3+"."+s4;
                        results.push_back(std::move(result));
                    }
                }
        return results;
    }

    bool isLegal(string s)
    {
        if (s.size()==0) return false;
        if (s.size()==1) return true;
        if (s.size()>3) return false;
        if (s[0]=='0') return false;
        if (stoi(s)<=255) return true;
        return false;
    }
    
};

int main(int argc, char const *argv[])
{

    unordered_set<int> set1;
    set1.insert(3);
    set1.count(3);
    std::unordered_map<int, int> IiMap;
    IiMap.insert({ 3, 3 });
    

        return 0;
}
