#include "../public/vintedrest.h"

static std::string extractCookie(cpr::Cookies cookies)
{
    for(auto& cookie : cookies)
    {
        if(cookie.GetName() == "_vinted_fr_session")
        {
            return cookie.GetValue();
        }
    }

    return std::string();
}

bool vintedrest::initCookies()
{
    cpr::Response response = this->get(VINTED_HOSTNAME);

    if (response.status_code != 200)
        return false;

    return true;
}

cpr::Response vintedrest::get(std::string url)
{
    this->m_logger->info("Making a request to " + url);

 
    cpr::Response response = cpr::Get(cpr::Url(url), cpr::Header{{"Cookie", "_vinted_fr_session=" + this->m_sessionCookie}});

    if (response.raw_header.contains("_vinted_fr_session"))
    {
        this->m_sessionCookie = extractCookie(response.cookies);
        this->m_logger->updatedCookie();
    }

    this->m_logger->info("Request ended with status code : " + std::to_string(response.status_code));

    return response;
}