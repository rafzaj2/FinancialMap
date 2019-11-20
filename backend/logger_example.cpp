#include "logger.h"


#define ENABLE_LOGGER




int main(int argc, char const *argv[])
{
    std::cout << "Start of Logger test" << std::endl;
    LOGGER_START(Logger::DEBUG, "logfile")
    LOGGER_WRITE(Logger::CONFIG, "input file is ")
    LOGGER_WRITE(Logger::DEBUG, "trying to allocate buffer")
    LOGGER_WRITE(Logger::ERROR, "exception caught: ")
    LOGGER_WRITE(Logger::WARNING, "no more particles")
    LOGGER_STOP()
    std::cout << "End of Logger test" << std::endl;
    return 0;
}
