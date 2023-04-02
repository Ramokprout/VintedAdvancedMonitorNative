#include "../public/vintedwindow.h"
#include "../public/interfont.h"
#include "../public/menuconstants.h"

// Initialize ImGui
void GLFWWindow::initImGui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(m_window.get(), true);
    ImGui_ImplOpenGL3_Init("#version 150");

    spdlog::info("Initialized ImGui");
}

void GLFWWindow::setEventCallback(const EventCallbackFn &callback)
{
    m_eventCallback = callback;
}

void GLFWWindow::onEvent()
{
    if (m_eventCallback)
    {
        m_eventCallback();
    }
}
void GLFWWindow::start()
{
    spdlog::info("GLFWWindow => Entering loop");
    while (!glfwWindowShouldClose(m_window.get()))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        drawImGuiContent();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_window.get());
    }
}

GLFWWindow::~GLFWWindow()
{
    spdlog::info("GLFWWindow => Cleaning memory..");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}

void VintedWindow::initStyle()
{
    this->m_client->GetLogger()->info("Init styles for ImGui.");
    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowTitleAlign = {0.5f, 0.5f};
    style.Colors[ImGuiCol_WindowBg] = this->hexToVec4(WINDOW_BACKGROUND_COLOR);
    style.Colors[ImGuiCol_ButtonHovered] = this->hexToVec4(BOUTON_HOVER_TABSELECTOR_COLOR, 0.75f);

    ImGui::GetIO().Fonts->AddFontFromMemoryCompressedBase85TTF(interfont_compressed_data_base85, 17.f);
}
