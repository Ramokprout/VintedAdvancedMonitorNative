#ifndef __VINTEDREST__
#define __VINTEDREST__

#include <cpr/cpr.h>
#include "vintedconstants.h"
#include "vintedlogger.h"
#include <string>
#include <iostream>

class vintedrest
{
public:
    vintedrest(std::shared_ptr<vintedlogger> logger)
    {
        this->m_logger = logger;
        this->initCookies();
    }

    cpr::Response get(std::string url);
    
    bool initCookies();

private:
    //cpr::Cookies m_cookies;
    std::string m_sessionCookie;
    std::shared_ptr<vintedlogger> m_logger;
};

#endif