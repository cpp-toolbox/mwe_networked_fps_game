cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES "src/*.cpp")
# Add the main executable
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DJPH_DEBUG_RENDERER)
        
find_package(enet)
find_package(glm)
find_package(spdlog)
find_package(fmt)
find_package(Jolt)
target_link_libraries(${PROJECT_NAME} enet::enet glm::glm spdlog::spdlog fmt::fmt Jolt::Jolt)
