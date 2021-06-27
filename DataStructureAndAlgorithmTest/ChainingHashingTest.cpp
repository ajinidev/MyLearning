#pragma once

#include "pch.h"
#include <gtest/gtest.h>
#include "ChainingHashing.h"

#define HASH_TABLE_SIZE 10
int hashingFunction(int val) { return (val % HASH_TABLE_SIZE); };
struct ChainingHashingTestFixture : public testing::Test {
    static int hashingFunction(int val) {
        return (val % HASH_TABLE_SIZE);
    };
    ChainingHashing<int, int>* tester;

    ChainingHashingTestFixture() : tester(new ChainingHashing<int, int>(hashingFunction, HASH_TABLE_SIZE)) {
        // DO nothing else
    }
    void SetUp() override {
        auto arr = { 10, 7, 15, 22, 9 };
        for (auto item : arr) {
            tester->insert(item, item);
        }
    }
   // int 
    void TearDown() override {}
};

TEST_F(ChainingHashingTestFixture, Base) {
    EXPECT_EQ(10, tester->value(10));
}

TEST_F(ChainingHashingTestFixture, ChainingTest) {
    tester->insert(17, 17);
    EXPECT_EQ(7, tester->value(7));
}

TEST_F(ChainingHashingTestFixture, EnhancedChainingTest) {
    tester->insert(17, 17);
    tester->insert(27, 27);
    EXPECT_EQ(17, tester->value(17));
    EXPECT_EQ(27, tester->value(27));
}

TEST_F(ChainingHashingTestFixture, IndexingTest) {
    tester->insert(17, 17);
    tester->insert(27, 27);
    EXPECT_EQ(17, (*tester)[17]);
    EXPECT_EQ(27, (*tester)[27]);
}
