#include <spdlog/spdlog.h>

#ifndef __VINTEDLOGGER__
#define __VINTEDLOGGER__

class vintedlogger
{
public:
    vintedlogger()
    {
        spdlog::info("CREATED VINTEDLOGGER SUCCESSFULLY");
    }

    const void updatedCookie()
    {
        spdlog::info("UPDATED COOKIE SUCCESSFULLY");
    }

    void info(std::string message)
    {
        spdlog::info(message);
    }
};

#endif