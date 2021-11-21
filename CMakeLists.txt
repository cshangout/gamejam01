cmake_minimum_required(VERSION 3.20)
project(gamejam01)

set(CMAKE_CXX_STANDARD 20)

# This directory is the assets directory we're going to copy to our build folder
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})

# Some build settings required for Javascript build
if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(LINKER_FLAGS "-s MAX_WEBGL_VERSION=2 -s MIN_WEBGL_VERSION=2 -s FULL_ES3=1 --preload-file ${ASSETS_DIR}@/assets")
    set(USE_FLAGS "-s USE_SDL=2 -s USE_FREETYPE=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS} ${LINKER_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
endif()

add_subdirectory(external/engine)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        hangout-engine
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        hangout-engine
)

if( NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    # Copy assets into build directory -- used for non-emscripten builds
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${ASSETS_DIR}/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
endif()