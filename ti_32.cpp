#include<string>
#include<iostream>
#include<sstream>
#include<istream>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<tuple>
#include<typeinfo>
using namespace std;


/*
    dp[i]表示第i个字符时，有效长度，
    
    当s[i]=(，则dp[i]=0。当s[i]=)，且s[i-1]=(时，dp[i]=dp[i-2]+2
    s[i]=)且s[i-1]=)时，如果s[i-1-dp[i-1]]='(',则应有三部分连起来，
    dp[i]=dp[i-1]+dp[i-1-dp[i-1]-1]+2
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen=0,n=s.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;++i)
        {
            if(s[i]==')')
            {
                if(s[i-1]='(')
                    dp[i]=i>=2? dp[i-2]+2:2;
                 else if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='(')
                    dp[i]=dp[i-1]+((i- dp[i-1]>=2)?dp[i-dp[i-1]-2]+2:2);
            } 
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};     


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}