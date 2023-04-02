cmake_minimum_required(VERSION 3.12)

project(vintedbot)

# Vérifiez que le compilateur prend en charge C++23
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
if(COMPILER_SUPPORTS_CXX23)
    add_compile_options("-std=c++23")
else()
    message(FATAL_ERROR "Le compilateur ne prend pas en charge C++23.")
endif()

# Téléchargement de GLFW depuis GitHub
include(FetchContent)
FetchContent_Declare(
  GLFW
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(GLFW)

# Téléchargement de GLEW depuis GitHub
FetchContent_Declare(
  GLEW
  GIT_REPOSITORY https://github.com/nigels-com/glew.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(GLEW)

# Téléchargement d'ImGui depuis GitHub
FetchContent_Declare(
  ImGui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        docking
)
FetchContent_MakeAvailable(ImGui)

# Télécharge CPR depuis GitHub
include(FetchContent)
FetchContent_Declare(
  CPR
  GIT_REPOSITORY https://github.com/whoshuu/cpr.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(CPR)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.9.2 # Vous pouvez également utiliser un tag spécifique ici
)
FetchContent_MakeAvailable(spdlog)

find_package(GLEW REQUIRED)



file(GLOB sources src/private/*.cpp)
file(GLOB imguisources ./include/imgui/*.cpp)



include_directories(./include/imgui)
include_directories(${GLEW_INCLUDE_DIRS})


add_executable(vintedbot ${sources} ${imguisources} src/main.cpp)
target_link_libraries(vintedbot PRIVATE cpr::cpr)
target_link_libraries(vintedbot PRIVATE cpr::cpr spdlog::spdlog)
target_link_libraries(vintedbot PRIVATE glfw)
target_link_libraries(vintedbot PRIVATE ${GLEW_LIBRARIES})
target_link_libraries(vintedbot PRIVATE GL)