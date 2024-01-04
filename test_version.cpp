#include "lib.h"
#include <gtest/gtest.h>

TEST(version, basic_test) {
    ASSERT_NE(version(), 100);
}
