#include <concepts>
#include <iostream>
#include <memory>
#include <string_view>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "vinted.h"

class GLFWWindow
{
public:
    using EventCallbackFn = std::function<void()>;

    GLFWWindow(int width, int height, std::string_view title)
        : m_width(width), m_height(height), m_title(title)
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            std::terminate();
        }

        // Set window hints
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Create the GLFW window
        m_window = std::shared_ptr<GLFWwindow>(
            glfwCreateWindow(m_width, m_height, m_title.data(), nullptr, nullptr),
            [](GLFWwindow *window)
            { glfwDestroyWindow(window); });

        if (!m_window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            std::terminate();
        }

        // Set the current context
        glfwMakeContextCurrent(m_window.get());

        // Initialize GLEW
        if (glewInit() != GLEW_OK)
        {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            glfwTerminate();
            std::terminate();
        }

        this->initImGui();
    }

    ImVec4 hexToVec4(const std::string& hex, float alpha = 1.0f)
    {
        unsigned int hexValue = std::stoul(hex.substr(1), nullptr, 16);

        float r = static_cast<float>((hexValue >> 16) & 0xFF) / 255.f;
        float g = static_cast<float>((hexValue >> 8) & 0xFF) / 255.f;
        float b = static_cast<float>((hexValue) & 0xFF) / 255.f;

        return ImVec4(r, g, b, alpha);
    }

    void initImGui();

    ~GLFWWindow();

    void setEventCallback(const EventCallbackFn &callback);

    void onEvent();
    void start();

protected:
    virtual void drawImGuiContent() {}

    int m_width;
    int m_height;
    std::string m_title;
    std::shared_ptr<GLFWwindow> m_window;

    EventCallbackFn m_eventCallback;
};

