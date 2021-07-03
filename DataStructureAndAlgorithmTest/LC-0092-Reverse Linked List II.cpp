#include "pch.h"
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    auto head = new ListNode(arr[0]);
    auto node = head;
    for (auto i = 1; i < arr.size(); i++) {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }
    return head;
}

string to_string(ListNode* head) {
    string str;
    while (head) {
        str += to_string(head->val);
        head = head->next;
    }
    cout << str;
    return str;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto node = head;
        auto i = 0;
        ListNode* prev = nullptr;
        while (node) {
            if (node->val == left) {
                break;
            }
            prev = node;
            node = node->next;
        }
        auto beg = prev ? prev : head;
        i++;
        stack<ListNode*> stack;
        while (node) {
            stack.push(node);
            if (node->val == right) {
                break;
            }
            node = node->next;
        }
        auto end = (node) ? node->next : nullptr;

        node = beg;
        if (node == nullptr) {
            head = stack.empty() ? nullptr : stack.top();
            if (!stack.empty()) stack.pop();
            node = head;
        }
        while (!stack.empty()) {
            node->next = stack.top();
            node = node->next;
            stack.pop();
        }
        node->next = end;
        return head;
    }
};

TEST(reverseBetween, TC1) {
    Solution tester;
    EXPECT_EQ(to_string(createList({ 1,4,3,2,5 })),
        to_string(tester.reverseBetween(createList({ 1,2,3,4,5 }), 2, 4)));
}

TEST(reverseBetween, TC2) {
    Solution tester;
    EXPECT_EQ(to_string(createList({ 5 })),
        to_string(tester.reverseBetween(createList({ 5 }), 1, 1)));
}