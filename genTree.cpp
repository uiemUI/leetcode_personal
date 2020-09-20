#include<vector>
//#include<deque>
using std::vector;
//* Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution
{
public:
    // 动态规划
    // 该子程序必须，用于计算n个不同的二叉搜索树
    // 输入为数字n，返回各种树的根节点，用向量表示
    // 测试用例n大于等于0小于等于8
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        // 首先定义一个n+1维的dp向量
        vector<vector<TreeNode *>> dp(n + 1);
        
        // 考虑base case
        TreeNode *first = new TreeNode(1); // 不用显示指定左右子树为空，初始化时就已经置空了
        dp[1] = {first};
        // 开始动态的计算，每次新树的时候都先复制一个树
        for (int i = 2; i <= n; i++)
        {
            // 然后对已经处理好的二叉树搜索树依次进行操作，在操作时，首先应该复制一个新的树，而不是直接再原来的基础上进行操作
            for (int j = 0; j < dp[i - 1].size(); j++)
            {
                // 当前以第j棵树为蓝本处理
                // 首先考虑i为根节点
                TreeNode *theIthNodeForRoot = new TreeNode(i);
                // 复制第j棵树并置为根节点的左子树，处理好了之后就放入最终结果中
                theIthNodeForRoot->left = copyTree(dp[i - 1][j]);
                dp[i].push_back(theIthNodeForRoot);

                // 然后一直往右走，首先初始化，然后考虑结尾，定义一个用于记录节点位次的变量
                TreeNode *currentNode = dp[i - 1][j];
                int nodePlace = 1;
                while (currentNode)
                {
                    // 每次循环时都创立一个新节点和复制当前的蓝本树
                    TreeNode *tempNode = new TreeNode(i);
                    TreeNode *newTreeRoot = copyTree(dp[i - 1][j]);
                    // 定义一个指针，并移动到新树的当前节点，然后将新节点插入
                    TreeNode *currentNode2 = newTreeRoot;
                    int nodePlace2 = nodePlace;
                    while (nodePlace2 > 1)
                    {
                        currentNode2 = currentNode2->right;
                        nodePlace2--;
                    }
                    TreeNode *newTreeCurrentLeftNode = currentNode2->right;
                    currentNode2->right = tempNode;
                    tempNode->left = newTreeCurrentLeftNode;
                    // 然后将新树插入到数组中
                    dp[i].push_back(newTreeRoot);
                    nodePlace++;
                    currentNode = currentNode->right;
                }
            }
        }

        return dp[n];
    }

    // 这是一个用于复制树的接口，用递归法
    // 输入根节点，返回复制好的树
    TreeNode *copyTree(TreeNode *root)
    {
        // 考虑递归基，没有根节点直接返回
        if (!root)
            return nullptr;
        // 此时表明有根节点了
        // 创建新的根节点
        TreeNode *newTreeRoot = new TreeNode(root->val);
        newTreeRoot->left = copyTree(root->left);
        newTreeRoot->right = copyTree(root->right);
        return newTreeRoot;
    }
};