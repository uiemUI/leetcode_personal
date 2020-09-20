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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> intMap;
        int sum=0;
        intMap.insert({0,-1});
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            if(k!=0)
                sum=sum%k;
            if(intMap.count(sum)>0)
                {
                    if((i-intMap[sum])>1)
                        return true;
                }
            else intMap.insert({sum,i});
        }
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().checkSubarraySum(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}