#include <logging/logging.h>
#include <gtest/gtest.h>
#include <sstream>
#include <thread>
#include <vector>
#include <mutex>

namespace log {
void check_log(const std::string& log);
// This test shows that log should be atomic otherwise log messages are mixed
// together
TEST(LoggingTest, trace) {
    std::ostringstream stream;
    Logging logging(stream);
    std::mutex log_mutex;

    std::thread first([&logging, &log_mutex] {
        for (int i = 0; i < 10; ++i) {
            std::stringstream sstring;

            // Resource Acquisition is Initialization
            std::lock_guard<std::mutex> lock(log_mutex);
            logging.trace("thread1 :\n");
            sstring << "Thread1: Interation n: " << i << "\n";
            logging.trace(sstring.str());  
        }
    });

    std::thread second([&logging, &log_mutex] {
        for (int i = 0; i < 10; ++i) {
            std::stringstream sstring;
            
            // Resource Acquisition is Initialization
            std::lock_guard<std::mutex> lock(log_mutex);
            logging.trace("thread2 :\n");
            sstring << "Thread2: Interation n: " << i << "\n";
            logging.trace(sstring.str());
        }
    });    
    
    first.join();
    second.join();

    check_log(stream.str());    
}

void check_log(const std::string& log)
{
    std::vector<std::string> trace_list;
    
    std::string token;
    std::istringstream tokenStream(log);
    while (std::getline(tokenStream, token, '\n'))
    {
       trace_list.push_back(token);
    }
    
    bool found_delimiter = false;
    bool is_thread1 = false;
    for (const auto& trace : trace_list)
    {
        if (found_delimiter)
        {
            if (is_thread1)
            {
                EXPECT_NE(std::string::npos, trace.find("Thread1"));
            }
            else
            {
                EXPECT_NE(std::string::npos, trace.find("Thread2"));
            }
        }
        
        if (trace == "thread1 :")
        {
            found_delimiter = true;
            is_thread1 = true;
            continue;
        }
        else if (trace == "thread2 :")
        {
            found_delimiter = true;
            is_thread1 = false;
            continue;
        }
        else
        {
            found_delimiter = false;
        }
    }
}
}
