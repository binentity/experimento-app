cmake_minimum_required(VERSION 3.30)
project(experimento_app)

set(CMAKE_CXX_STANDARD 23)
set(SFML_STATIC_LIBRARIES ON)

# Needs to be decomposed.
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        main
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Starting attach detection.
find_package(
        SFML 3
        REQUIRED
        COMPONENTS
        Graphics
        Audio
        Network
        System
        Window
)

# Application assembly.

add_executable(
        experimento_app
        main.cc
        world.cc
        world.h
        system.h
        base-system.cc
        base-system.h
)

target_link_libraries(
        experimento_app
        PRIVATE
        SFML::Graphics
        SFML::Audio
        SFML::Network
        SFML::System
        SFML::Window
)

# Test app assembly.

add_executable(
        my_tests
        test/test_main.cc
)

target_link_libraries(
        my_tests
        gtest_main
)