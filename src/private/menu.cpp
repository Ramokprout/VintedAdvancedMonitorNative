#include "../public/window.h"

void VintedWindow::drawButton(const std::string &name)
{
   ImGui::PushStyleColor(ImGuiCol_Button, this->hexToVec4("#181B20"));
   // ImGui::SetCursorPosY(ImGui::GetCursorPosY()+10);
    ImGui::SetNextItemWidth(150.f);
    ImGui::Button(name.c_str(), ImVec2(ImGui::GetWindowContentRegionWidth(), 60.f));
    ImGui::PopStyleColor();
}

void VintedWindow::drawImGuiContent()
{
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Appearing);
    ImGui::SetNextWindowPos({0.f, 0.f}, ImGuiCond_Appearing);
    ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImVec2 fullSize = ImGui::GetIO().DisplaySize;

    ImVec2 ChildSize = {150.f, 500.f};
    ImVec2 restSize;

    restSize.x = fullSize.x - ChildSize.x;
    restSize.y = fullSize.y;

    ImGui::SetCursorPos({0.f, 0.f});
    ImGui::PushStyleColor(ImGuiCol_ChildBg, this->hexToVec4("#17191D"));
    if (ImGui::BeginChild("##selectmenu", ChildSize, true))
    {
        //ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.f, 0.f));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));
        this->drawButton("slt");
        this->drawButton("cv");
        ImGui::PopStyleVar(2);
        ImGui::EndChild();
    }
    ImGui::PopStyleColor();

    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5.f);
    if (ImGui::BeginChild("##content", restSize, false))
    {
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::Text("Contenu de la fenetre");
        ImGui::EndChild();
    }

    ImGui::End();
}