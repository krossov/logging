#include "logging.h"

namespace krv {
    Logging::~Logging()
    {
        out_ << std::flush;
    }

    void Logging::trace(const std::string& str)
    {
        out_ << str;
    }
}
