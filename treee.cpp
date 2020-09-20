#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<istream>
#include<sstream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int rob(TreeNode *root)
    {
        queue<TreeNode *> dec;
        if (root == nullptr)
            return 0;
        int firAns = 0;
        int secAns = 0;
        int flag = 0;
        dec.push(root);
        //firAns+=root->val;
        // if(root->left)
        //     dec.push(root->left);
        // if(root->right)
        //     dec.push(root->right);
        while (!dec.empty())
        {
            int decSize = dec.size();
            ++flag;
            for (size_t i = 0; i < decSize; ++i)
            {

                auto node = dec.front();
                dec.pop();
                if (flag % 2)
                    secAns += node->val;
                else
                    firAns += node->val;
                if (node->left)
                    dec.push(node->left);
                if (node->right)
                    dec.push(node->right);
            }
        }
        return max(firAns, secAns);
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);

        int ret = Solution().rob(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}