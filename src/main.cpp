#include "public/vinted.h"
#include "public/vintedwindow.h"

int main(void)
{
    spdlog::set_level(spdlog::level::trace);
    vinted* client = new vinted();

    VintedWindow window = VintedWindow(client);
    window.initStyle();
    window.start();

    delete client;
    return 0;
}