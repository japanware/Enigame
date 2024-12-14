cmake_minimum_required(VERSION 3.30)
project(Enigame)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Check the build type and define a macro accordingly
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE_BUILD)
endif()

add_executable(Enigame src/main.cpp
        src/AssetManager.cpp
        src/AssetManager.h
        src/Entity.cpp
        src/Entity.h
        src/Game.cpp
        src/Renderer.h
        src/Scene.cpp
        src/Scene.h
        src/SceneManager.cpp
        src/SceneManager.h
        src/Utils.cpp
        src/Utils.h
        src/IntroScene.cpp
        src/IntroScene.h
        src/LoadingScene.cpp
        src/LoadingScene.h
        src/InputManager.cpp
        src/InputManager.h)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(Enigame PRIVATE raylib)