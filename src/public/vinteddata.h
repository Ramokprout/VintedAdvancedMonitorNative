#include <unordered_map>
#include "vintedrest.h"
#include "vinteddatastructrures.h"

class vinteddata
{
public:
    vinteddata(vintedrest *rest)
    {
        this->m_rest = rest;
        this->fetchBrands();
    }

    // cette fonction récupère toutes les marques disponibles sur vinted et les met dans un std::unordered_map

    std::unordered_map<std::string, brand_t> getCachedBrands() const
    {
        return this->brands;
    }

        ~vinteddata()
    {
        this->brands.clear();
    }


private:

    void fetchBrands();

    std::unordered_map<std::string, brand_t> brands;

    vintedrest *m_rest;
};
