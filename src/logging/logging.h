#pragma once

#include <string>
#include <iostream>
#include "logging_message.h"

namespace krv {
class Logging
{
    public:
        Logging(std::ostream& out) :
            out_(out)
        {}

        virtual ~Logging();        
        void trace(const std::string& str);
        LoggingMessage new_message();

    private:
    std::ostream& out_;
};
}
