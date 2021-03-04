/**
 * Definition for a binary tree node.*/
#include"stand.h"

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    vector<int> inorder_;
    vector<int> postorder_;
    unordered_map<int,int> inMap_;
    unordered_map<int,int> posMap_;
    TreeNode* buildTree(int inB,int inE,int posB,int posE)
    {
        if((inE-inB)<=0)
            return nullptr;
        if((inE-inB)==1)
            return (new TreeNode{inorder_[inB]});
        int rootVal = postorder_[posE-1];
        auto root = new TreeNode(rootVal);
        int ninE =inMap_[rootVal];//这里没考虑ninE是边界的情况
        if(ninE==inE)
        {
             root->left=buildTree(inB,ninE,posB,posE-1);
             return root;
        }
        //int ninB=inMap_[rootVal]+1;
        //int nVal = inorder_[ninE+1];
        //int nposB = posMap_[nVal];
        int nposB = posB+(ninE-inB);//这里nposb保证数量一样
        root->left=buildTree(inB,ninE,posB,nposB);
        root->right=buildTree(ninE+1,inE,nposB,posE-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        inorder_= inorder;
        postorder_=postorder;
        for(int i =0;i<inorder.size();i++)
        {
            inMap_[inorder[i]]=i;
            posMap_[postorder[i]]=i;
        
        }
        return buildTree(0,inorder.size(),0,postorder.size());
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

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}