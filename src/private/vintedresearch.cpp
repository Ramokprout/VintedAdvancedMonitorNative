#include "../public/vintedresearch.h"

bool vintedresearch::AddBrand(brand_t brand)
{
    if (!this->search.brands)
    {
        this->search.brands = (brand_t *)malloc(sizeof(brand_t));
        if (!this->search.brands)
            return false;
        this->search.brandCount = 1;
        this->search.brands[0] = brand;
        return true;
    }

    for (int i = 0; i < this->search.brandCount; i++)
    {
        if (this->search.brands[i].id == brand.id)
        {
            return false;
        }
    }

    this->search.brandCount++;

    brand_t *newArray = (brand_t *)realloc(this->search.brands, this->search.brandCount * sizeof(brand_t));
    if (!newArray)
    {
        return false;
    }

    this->search.brands = newArray;
    this->search.brands[this->search.brandCount - 1] = brand;
    return true;
}

bool vintedresearch::RemoveBrandAtIndex(int index) {
    if(index < 0 || index >= this->search.brandCount)
    {
        return false;
    }

    for(int i = index; i < this->search.brandCount - 1; i++)
    {
        this->search.brands[i] = this->search.brands[i + 1];
    }

    this->search.brandCount--;

    brand_t* newArray = (brand_t*)realloc(this->search.brands, this->search.brandCount * sizeof(brand_t));
    if(this->search.brandCount > 0 && !newArray)
    {
        return false;
    }

    this->search.brands = newArray;
    return true;
}