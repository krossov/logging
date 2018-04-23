#include <gtest/gtest.h>
#include <logging/logging.h>
#include <logging/logging_message.h>
#include <sstream>

namespace krv {
TEST(LoggingMessageTest, push)
{
    std::ostringstream stream;
    Logging logging(stream);

    {
        auto message = logging.new_message();
        message.push("Hello").push(" World!");
    }

    EXPECT_STREQ("Hello World!", stream.str().c_str());
}
}