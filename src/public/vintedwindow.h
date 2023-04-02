#include <array>
#include "window.h"

static std::array<std::string, 4> CATEGORIES{
    {"VintedCaca", "VintedStp", "Pénétration", "ANNA KAPLANIAN"}
};

class VintedWindow : public GLFWWindow
{
public:

    VintedWindow(vinted* client) : GLFWWindow(700, 500, "Vinted Monitor Configuration") {
        this->m_client = client;
    }

    using GLFWWindow::GLFWWindow;

    void initStyle();

protected:
    void drawButton(int id);

    void drawImGuiContent() override;

    void drawTabSelector();
    void drawWindowContent(ImVec2 size);

private:
    vinted* m_client;
    int activeTab = 0;
};