#include <logging/logging.h>
#include <gtest/gtest.h>
#include <sstream>
#include <thread>


namespace log {
TEST(LoggingTest, trace) {
    std::ostringstream stream;
    Logging logging(stream);
    
    std::thread first([&logging] {
        for (int i = 0; i < 10; ++i) {
            std::stringstream sstring;

            logging.trace("thread1 :\n");
            sstring << "Thread1: Interation n: " << i << "\n";
            logging.trace(sstring.str());  
        }
    });

    std::thread second([&logging] {
        for (int i = 0; i < 10; ++i) {
                        std::stringstream sstring;

            logging.trace("thread2 :\n");
            sstring << "Thread2: Interation n: " << i << "\n";
            logging.trace(sstring.str());
        }
    });    
    
    first.join();
    second.join();

    std::cout << stream.str() <<std::endl;    
}
}
