#include "../public/window.h"

// Initialize ImGui
void GLFWWindow::initImGui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(m_window.get(), true);
    ImGui_ImplOpenGL3_Init("#version 150");
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
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}

void VintedWindow::initStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowTitleAlign = {0.5f, 0.5f};
    style.Colors[ImGuiCol_WindowBg] = this->hexToVec4("#181B20");
}

