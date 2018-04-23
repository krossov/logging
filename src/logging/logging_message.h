#pragma once
#include <sstream>
#include <memory>

namespace krv {
class Logging;
class LoggingMessage
{
public:
    LoggingMessage(Logging& logging);
    virtual ~LoggingMessage();

    LoggingMessage& operator=(LoggingMessage&&) = default;
    LoggingMessage(LoggingMessage&&) = default;

    void set_logging(Logging* logging);
    template<typename T> LoggingMessage& push(const T& t)
    {
        uptr_stream_ << t;
        return *this;
    }

private:
    Logging& logging_;
    std::stringstream uptr_stream_;
};
}
