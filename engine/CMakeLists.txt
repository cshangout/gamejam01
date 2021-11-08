cmake_minimum_required(VERSION 3.20)
project(hangout-engine)

set(CMAKE_CXX_STANDARD 20)

# Some build settings required for Javascript build
if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(USE_FLAGS "-s USE_SDL=2 -s USE_FREETYPE=1 -s MAX_WEBGL_VERSION=2 -s MIN_WEBGL_VERSION=2 --preload-file ${PROJECT_SOURCE_DIR}/assets@/assets")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
endif()

add_subdirectory(external/SDL)
add_subdirectory(external/glm)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENGL_LIBRARY OpenGL::GL)
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        glm
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${OPENGL_LIBRARY}
        SDL2main
        SDL2-static
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glm
    PRIVATE
        ${OPENGL_LIBRARY}
        SDL2main
        SDL2-static
)