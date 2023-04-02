#include <array>
#include "window.h"

class VintedWindow : public GLFWWindow
{
public:

    VintedWindow(vinted* client) : GLFWWindow(700, 500, "Vinted Monitor Configuration") {
        this->m_client = client;
        memset(this->queryGenerator.searchString, 0, 256);
    }

    using GLFWWindow::GLFWWindow;

    void initStyle();

protected:
    void drawButton(int id);

    void drawImGuiContent() override;

    void drawTabSelector();
    void drawWindowContent(ImVec2 size);

    void firstMenu();
    void secondMenu();
    void thirdMenu();
    void fourthMenu();

private:
    vinted* m_client;
    int activeTab = 0;

    struct {
        char searchString[256];
        std::set<std::shared_ptr<brand_t>> selectedBrands;
    } queryGenerator;
};