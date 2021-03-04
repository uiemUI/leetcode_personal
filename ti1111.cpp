/*
 * @Author: uiemUI
 * @Date: 2021-02-18 09:34:14
 * @LastEditTime: 2021-02-18 09:34:27
 * @LastEditors: uiemUI
 * @Description:
 * @FilePath: \leetcode_personal\ti1111.cpp
 */
#include"stand.h"
class DiningPhilosophers {
public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {
        scoped_lock lock(mutexes_[philosopher], mutexes_[(philosopher + 1) % 5]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    vector<mutex> mutexes_ = vector<mutex>(5);
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int target = stringToInteger(line);

        int ret = Solution().foobar(target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}