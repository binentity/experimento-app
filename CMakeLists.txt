cmake_minimum_required(VERSION 3.28)
project(experimento_app)

set(CMAKE_CXX_STANDARD 23)
set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 REQUIRED COMPONENTS
        Graphics Audio Network System Window)

add_executable(experimento_app
        main.cc)

target_link_libraries(experimento_app PRIVATE
        SFML::Graphics SFML::Audio SFML::Network SFML::System SFML::Window)
