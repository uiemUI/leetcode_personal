#include"stand.h"

class Solution
{
private:
    vector<int> marked;
    vector<int> path;
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
            if (marked[next] == 0 && adj.count(next))
                dfs(next);
        }
        path[w] = 0;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        //这题就是检测是否有环
        if (prerequisites.empty())
            return true;
        hasCycle = false;

        marked = vector<int>(numCourses, 0);
        path = vector<int>(numCourses, 0);
        for (auto &courses : prerequisites)
        {
            adj[courses[1]].insert(courses[0]);
        }
        for (auto &courses : prerequisites)
            dfs(courses[1]);

        return !hasCycle;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> course({{0,2},{1,2},{2,0}});
    auto result = Solution().canFinish(3, course);
    cout<<result<<endl;

    return 0;
}
