#pragma once

#include "pch.h"
#include <gtest/gtest.h>
#include "BracketSymmetryProblem.h"


TEST(BracketSymmetryProblem, Pass) {
    BracketSymmetryProblem tester;
    EXPECT_EQ(false, tester.isValidBrackets("[{})[]"));
}

TEST(BracketSymmetryProblem, Fail) {
    BracketSymmetryProblem tester;
    EXPECT_EQ(true, tester.isValidBrackets("[[{}]()]"));
}
