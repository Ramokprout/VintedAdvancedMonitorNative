#include <unordered_map>
#include <string>

constexpr const char *VINTED_HOSTNAME = "https://www.vinted.be";
constexpr const char *VINTED_BRANDS = "https://www.vinted.be/api/v2/brands/popular";

static std::array<std::string, 4> CATEGORIES{
    {"VintedCaca", "VintedStp", "MAXIPROUT", "AAAAAAAAAAAA"}
};

enum categories_e {
    VINTEDCACA,
    VINTEDSTP,
    MAXIPROUT,
    AAAAAAAAAAAA
};

static std::unordered_map<int, std::string> COLORS = {
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