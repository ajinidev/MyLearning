#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "Tries.h"


struct TrieTestFixture : public testing::Test {
    Trie<int> tester;
    void SetUp() override {
        tester.setDefaultValue(int(0));
        auto arr = { "Abhijith", "Ajini", "Athira", "Jyolsna", "Anvi" };
        for (auto item : arr) {
            tester.insert(item, 1);
        }
    }
    void TearDown() override {
    }

    static std::string to_string(int val) { return std::to_string(val); };
};

TEST_F(TrieTestFixture, Found) {
    EXPECT_EQ(1, tester.getValue("Abhijith"));
}

TEST_F(TrieTestFixture, NotFound) {
    tester.insert("abhijithdev", 1);
    tester.remove("abhijithdev");
    EXPECT_EQ(0, tester.getValue("abhijithdev"));
}

TEST_F(TrieTestFixture, FoundAfterRemovalOfExtended) {
    tester.insert("abhijithdev", 1);
    tester.remove("abhijithdev");
    EXPECT_EQ(1, tester.getValue("Abhijith"));
}

TEST_F(TrieTestFixture, FoundAfterRemovalOfExisting) {
    tester.insert("abhijithdev", 1);
    tester.remove("Abhijith");
    EXPECT_EQ(1, tester.getValue("abhijithdev"));
}