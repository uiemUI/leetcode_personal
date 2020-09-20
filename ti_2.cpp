#include "stand.h"

/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr || l2 == nullptr)
            return nullptr;
        ListNode *ResNode;
        int firLeft = l1 == nullptr ? 0 : l1->val;
        int firRight = l2 == nullptr ? 0 : l2->val;
        int fir = firLeft + firRight;
        int decVal = 0; //残项
        if (fir >= 10)
        {
            fir = fir - 10;
            decVal = 1;
        }
        ResNode = new ListNode(fir);
        ListNode *nextNode = ResNode;
        l1 = l1 == nullptr ? l1 : l1->next;
        l2 = l2 == nullptr ? l2 : l2->next;
        while (l1 != nullptr || l2 != nullptr)
        {
            int valLeft = l1 == nullptr ? 0 : l1->val;
            int valRight = l2 == nullptr ? 0 : l2->val;
            int val = valLeft + valRight + decVal;
            decVal = 0;
            if (val >= 10)
            {
                val -= 10;
                decVal = 1;
            }
            nextNode->next = new ListNode(val);
            nextNode = nextNode->next;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }
        if (decVal == 1)
        {
            nextNode->next = new ListNode(1);
        }
        return ResNode;
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

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *l1 = stringToListNode(line);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}