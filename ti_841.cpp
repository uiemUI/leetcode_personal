#include"stand.h"

class Solution
{
private:
    unordered_set<int> Nset;
    bool dfs(int i, vector<vector<int>> &rooms)
    {
        if (Nset.size() == rooms.size())
            return true;
        if (i >= rooms.size())
            return false;
        auto &tempVector = rooms[i];
        //if(tempVector.empty()) return false;
        for (auto temp : tempVector)
        {
            if (Nset.count(temp))
                continue;
            Nset.insert(temp);
            if (dfs(temp, rooms))
                return true;
            //Nset.erase(temp);
        }
        return false;
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        Nset.insert(0);
        return dfs(0, rooms);
    }
};





int main(int argc, char const *argv[])
{
    vector<vector<int>> rooms{
        {2, 3}, {1,2}, {2,5}, {1, 4}};
    //bool restult = Solution().canVisitAllRooms(rooms);
    sort(rooms.begin(), rooms.end(), [](vector<int> &left, vector<int> &right) { return right.back()>left.back(); });
    auto pp(rooms);
    sort(rooms.begin(), rooms.end(), [](auto &left, auto &right) { return right.back() <left.back(); });
    auto ppt(rooms);
    return 0;
}
