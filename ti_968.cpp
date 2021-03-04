#include"stand.h"


/**
  Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
    struct Status {int a,b,c;}; 
    /** 
     * a代表该节点需要安装相机，b代表该节点已被子树的相机覆盖，
     * c代表该节点未被覆盖，需要父节点的相机覆盖
     * a = lc+rc+1
     * b = min(la+rb,lb+ra)
     * c=lb+rb
     * 因为 b = min(la+rb,lb+ra)当该节点为nullptr时，返回a=int_max,b=0,c=0
     * 使其选择另一颗子树相关的值.
     * 考虑到只是b,c可能
     * */
    Status dfs(TreeNode* root) {
        if(!root) return {INT_MAX/2,0,0};
        auto [la,lb,lc]=dfs(root->left);
        auto[ra,rb,rc]=dfs(root->right);
        int a = lc+rc+1;  
        int b =min(a, min(la+rb,lb+ra));//可能会出现min(la+rb,lb+ra)不满足全覆盖的条件，所以需要在该节点添加摄像机,比如说单独一个[0]
        //下同
        int c = min(a,lb+rb);
        return {a,b,c};
    }
public:
    int minCameraCover(TreeNode* root) {
        auto [a,b,c] = dfs(root);
        return b;
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().minCameraCover(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}