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

private:
    ~vinteddata()
    {
        this->brands.clear();
        this->colors.clear();
    }

    void fetchBrands();

    std::unordered_map<std::string, brand_t> brands;
    std::unordered_map<int, std::string> colors = {
        {1, "Noir"},
        {3, "Gris"},
        {12, "Blanc"},
        {20, "Crème"},
        {4, "Beige"},
        {21, "Abricot"},
        {11, "Orange"},
        {22, "Corail"},
        {7, "Rouge"},
        {23, "Bordeaux"},
        {24, "Rose"},
        {6, "Violet"},
        {25, "Bleu clair"},
        {9, "Bleu"},
        {27, "Marine"},
        {17, "Turquoise"},
        {30, "Menthe"},
        {10, "Vert"},
        {28, "Vert foncé"},
        {16, "Kaki"},
        {2, "Marron"},
        {29, "Moutarde"},
        {8, "Jaune"},
        {13, "Argenté"},
        {14, "Doré"},
        {15, "Multicolore"},
    };

    vintedrest *m_rest;
};
