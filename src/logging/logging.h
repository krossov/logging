#pragma once

#include <string>
#include <iostream>

namespace krv {
class Logging
{
    public:
        Logging(std::ostream& out) :
            out_(out)
        {}

        virtual ~Logging();        
        void trace(const std::string& str);

    private:
    std::ostream& out_;
};
}
