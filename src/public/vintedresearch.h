#include "vinteddatastructrures.h"

class vintedresearch
{
public:
    vintedresearch()
    {
        memset(&search, 0, sizeof(search));
    }

    bool AddBrand(brand_t brand);
    bool RemoveBrandAtIndex(int index);

private:
    search_t search;
};