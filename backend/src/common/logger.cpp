#include "logger.h"


using namespace std;
 
// --------------------------------------
// static members initialization
// --------------------------------------
 
const string Logger::PRIORITY_NAMES[] =
{
    "DEBUG",
    "CONFIG",
    "INFO",
    "WARNING",
    "ERROR"
};
 
Logger Logger::instance;
 
 
// --------------------------------------
// function implementations
// --------------------------------------
 
Logger::Logger() : active(false) {}
 
void Logger::Start(Priority minPriority, const string& logFile)
{
    std::cout << "Logger::Start() function execution with priority equal to " << minPriority << std::endl;
    instance.active = true;
    instance.minPriority = minPriority;
    if (logFile != "")
    {
        instance.fileStream.open(logFile.c_str());
    }
}
 
void Logger::Stop()
{
    std::cout << "Logger::Stop() function execution" << std::endl;
    instance.active = false;
    if (instance.fileStream.is_open())
    {
        instance.fileStream.close();
    }
}
 
void Logger::Write(Priority priority, const string& message)
{
    std::cout << "Logger::Write() function execution" << std::endl;
    if (instance.active && priority >= instance.minPriority)
    {
        // identify current output stream
        ostream& stream
            = instance.fileStream.is_open() ? instance.fileStream : std::cout;
 
        stream  << PRIORITY_NAMES[priority]
                << ": "
                << message
                << endl;
    }
}
