#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "Graph.h"

struct GraphTestFixture : public testing::Test {
    Graph<int> tester;
    typedef Graph<int>::Node GNode;
    GNode *a, *b, *c, *d, *e, *f, *g, *h;
    void SetUp() override {
        a = new GNode(1);
        b = new GNode(2);
        c = new GNode(3);
        d = new GNode(4);
        e = new GNode(5);
        f = new GNode(6);
        g = new GNode(7);
        h = new GNode(8);

        a->neighbors.push_back(b);
        a->neighbors.push_back(c);

        b->neighbors.push_back(d);
        b->neighbors.push_back(e);

        c->neighbors.push_back(f);
        c->neighbors.push_back(g);

        a->neighbors.push_back(h);
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(GraphTestFixture, BFS) {
    EXPECT_EQ("12384567", tester.bfs(to_string, a));
}

TEST_F(GraphTestFixture, DFS) {
    EXPECT_EQ("18376254", tester.dfs(to_string, a));
}