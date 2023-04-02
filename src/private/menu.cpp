#include "../public/vintedwindow.h"
#include "../public/menuconstants.h"

void VintedWindow::drawButton(int id)
{
    const std::string &name = CATEGORIES.at(id);
    const char *hexColor = this->activeTab == id ? BOUTON_ACTIVE_TABSELECTOR_COLOR : BOUTON_TABSELECTOR_COLOR;
    ImVec4 color = this->hexToVec4(hexColor);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, BOUTON_TABSELECTOR_ROUNDING);
    ImGui::PushStyleColor(ImGuiCol_Button, color);
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + BOUTON_TABSELECTOR_SPACING);
    if (ImGui::Button(name.c_str(), ImVec2(ImGui::GetWindowContentRegionWidth(), BOUTON_TABSELECTOR_HEIGHT)))
    {
        this->activeTab = id;
    }
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
}

void VintedWindow::drawImGuiContent()
{
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Appearing);
    ImGui::SetNextWindowPos({0.f, 0.f}, ImGuiCond_Appearing);
    ImGui::Begin("##prout", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImVec2 fullSize = ImGui::GetIO().DisplaySize;
    fullSize.x -= TABSELECTOR_SIZE.x;

    this->drawTabSelector();
    this->drawWindowContent(fullSize);

    ImGui::End();
}

void VintedWindow::drawTabSelector() {
    ImGui::SetCursorPos({0.f, 0.f});
    ImGui::PushStyleColor(ImGuiCol_ChildBg, this->hexToVec4(TABSELECTOR_BACKGROUND_COLOR));
    if (ImGui::BeginChild("##selectmenu", TABSELECTOR_SIZE, true))
    {
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.f, 0.f));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));

        for (int i = 0; i < CATEGORIES.size(); i++)
        {
            this->drawButton(i);
        }

        ImGui::PopStyleVar(2);
        ImGui::EndChild();
    }
    ImGui::PopStyleColor();
    ImGui::SameLine();
}

void VintedWindow::drawWindowContent(ImVec2 size) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + INITIAL_CONTENT_WINDOW_PADDING);
    if (ImGui::BeginChild("##content", size, false))
    {
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::EndChild();
    }
}