#include "../public/vinteddata.h"


void vinteddata::fetchBrands() {

    cpr::Response response = this->m_rest->get(VINTED_BRANDS);
    if(response.status_code != 200)
    {
        spdlog::critical("Failed to fetch brands, throwing error.");
        throw std::runtime_error("Can't fetch brands.");
    }

    nlohmann::json json = nlohmann::json::parse(response.text);

    if(json.find("brands") == json.end())
    {
        spdlog::critical("Failed to fetch brands, throwing error.");
        throw std::runtime_error("Can't fetch brands.");
    }

    for(auto& brandJson : json["brands"])
    {
        brand_t brandObject = brand_t::jsonToBrand(brandJson);
        this->brands.insert(std::make_pair(brandObject.title, brandObject));

        spdlog::trace("Added brand " + brandObject.title + " to the list of brands.");
    }
}