#ifndef __VINTEDDATASTRUCTURES__
#define __VINTEDDATASTRUCTURES__

#include <string>
#include "libraries/json.hpp"


template <typename T>
static void convertToData(nlohmann::json json, std::string key, T* buffer)
{
    if(json.find(key) != json.end())
    {
        *buffer = json[key].get<T>();
    }
}

struct brand_t {
    int id;
    std::string title;
    bool requires_authenticity_check;
    bool is_luxury;

    static brand_t jsonToBrand(nlohmann::json& json)
    {
        brand_t result;
        convertToData<int>(json, "id", &result.id);
        convertToData<std::string>(json, "title", &result.title);
        convertToData<bool>(json, "requires_authenticity_check", &result.requires_authenticity_check);
        convertToData<bool>(json, "is_luxury", &result.is_luxury);
        
        return result;
    } 
};

struct search_t {
    brand_t* brands;
    int brandCount;
    int* colors;
    int colorCount;
};

#endif