#include "logging_message.h"
#include "logging.h"

namespace krv {
LoggingMessage::LoggingMessage(Logging& logging):
    logging_(logging)
{
}

LoggingMessage::~LoggingMessage()
{
    logging_.trace(uptr_stream_.str());
}

template LoggingMessage& LoggingMessage::push<std::string>(const std::string& t);
}
