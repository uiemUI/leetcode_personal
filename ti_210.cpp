#include"stand.h"

class Solution
{
private:
    vector<int> marked;
    vector<int> path;
    vector<int> orders;
    unordered_map<int, unordered_set<int>> adj; //一个顶点多条边
    bool hasCycle;

    void dfs(int w)
    {
        if (marked[w])
            return;
        marked[w] = 1;
        path[w] = 1;

        if (hasCycle)
            return;
        for (auto next : adj[w])

        {
            if (path[next] == 1)
            {
                hasCycle = true;
                return;
            }
            if (marked[next] == 0)
                dfs(next);
        }
        path[w] = 0;
        orders.push_back(w);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        orders.reserve(numCourses);
        if (prerequisites.empty())
        {
            for (int i = 0; i < numCourses; i++)
                orders.push_back(i);
            reverse(orders.begin(), orders.end());
            return orders;
        }
        hasCycle = false;
        //orders.reserve(numCourses);
        marked = vector<int>(numCourses, 0);
        path = vector<int>(numCourses, 0);
        for (auto &courses : prerequisites)
        {
            adj[courses[1]].insert(courses[0]);
        }
        // for (auto &courses : prerequisites)
        //     dfs(courses[1]);
        for (int i = 0; i < numCourses && (!hasCycle); ++i)
        {
            dfs(i);//对所有顶点都遍历
        }
        reverse(orders.begin(), orders.end());
        if (hasCycle)
            return {};
        return orders;
    }
};
int main(int argc, char const *argv[])
{
    //vector<vector<int>> course({{0, 2}, {1, 2}, {2, 0}});
    vector<vector<int>> course({{1,0}});
    auto result = Solution().findOrder(2, course);
    cout << "pass"<< endl;

    return 0;
}
