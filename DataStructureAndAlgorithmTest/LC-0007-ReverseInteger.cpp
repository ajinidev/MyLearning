#include "pch.h"
#include <string>
using namespace std;

class ReverseInteger {
public:
    int reverse(int x) {
        long result = 0;
        while (x) {
            result *= 10;
            result += x % 10;
            x = x / 10;
        }

        if (-pow(2, 31) <= result && result <= pow(2, 31) - 1)
        {
            return result;
        }
        return 0;
    }

};


TEST(ReverseIntegerTest, NormalTree) {
    ReverseInteger tester;
    EXPECT_EQ(231, tester.reverse(132));
}