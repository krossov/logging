#include <logging/logging.h>
#include <gtest/gtest.h>

namespace log {
TEST(LoggingTest, trace) {
    Logging logging;
    logging.trace("toto");
    EXPECT_TRUE(false);
}
}
