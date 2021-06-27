#pragma once
#include "pch.h"
#include <vector>
#include <string>
#include <gtest/gtest.h>
using namespace std;

namespace MergeKLinkedList {

    struct Node {
        Node* next;
        int value;

        Node(int n) : value(n), next(nullptr) {}
    };

    Node* createLinkedList(vector<int> ip) {
        if (ip.empty()) return nullptr;
        auto head = new Node(ip[0]);
        auto node = head;
        for (auto i = 1; i < ip.size(); i++) {
            node->next = new Node(ip[i]);
            node = node->next;
        }
        return head;
    }

    Node* mergeTwoNodes(Node* node1, Node* node2) {
        Node* head = nullptr;
        if (node1->value < node2->value) {
            head = new Node(node1->value);
            node1 = node1->next;
        }
        else {
            head = new Node(node2->value);
            node2 = node2->next;
        }
        auto node = head;
        while (node1 && node2) {
            if (node1->value < node2->value) {
                node->next = new Node(node1->value);
                node1 = node1->next;
            }
            else {
                node->next = new Node(node2->value);
                node2 = node2->next;
            }
            node = node->next;
        }
        if (node1) {
            node->next = node1;
        }
        if (node2) {
            node->next = node2;
        }
        return head;
    }

    Node* mergeNodes(vector<Node*> ips) {
        if (ips.empty()) return nullptr;
        if (ips.size() == 1) return ips[0];
        int i = 0;
        int j = ips.size() - 1;
        vector<Node*> temp;
        while (i <= j) {
            temp.push_back(mergeTwoNodes(ips[i], ips[j]));
            i++;
            j--;
            if (i == j) {
                temp.push_back(ips[i]);
                break;
            }
        }
        return mergeNodes(temp);
    }

    string print(Node* node) {
        string str = "";
        while (node) {
            str += std::to_string(node->value);
            node = node->next;
        }
        return str;
    }
}


struct MergeKLinkedListTestFixture : public testing::Test {
    vector<MergeKLinkedList::Node*> tester;
    void SetUp() override {
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,3,4,5,6,7 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,4,6,7,9 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,3,4,5,6,7 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,4,6,7,9 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,3,4,5,6,7 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,4,6,7,9,13 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,3,4,5,6,7 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,4,6,7,9 }));
        tester.push_back(MergeKLinkedList::createLinkedList({ 1,3,4,5,6,7,11,99 }));
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(MergeKLinkedListTestFixture, NormalTree) {
    string exp = "11111111133333444444444555556666666667777777779999111399";
    auto out = MergeKLinkedList::print(MergeKLinkedList::mergeNodes(tester));
    EXPECT_EQ(exp, out);
}