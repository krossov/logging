#pragma once

#include <string>

namespace log {
class Logging
{
    public:
        Logging() = default;
        virtual ~Logging() = default;
        void trace(const std::string& str);
};
}
