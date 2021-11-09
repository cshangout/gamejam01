cmake_minimum_required(VERSION 3.20)
project(hangout-engine)

set(CMAKE_CXX_STANDARD 20)

# Outputs builds to the /dist directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})

add_subdirectory(external/SDL)
add_subdirectory(external/glm)
add_subdirectory(external/glad)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES} include/hangout_engine/rendering/types.h src/rendering/opengl/open_gl_buffer.cpp src/rendering/opengl/open_gl_buffer.h)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENGL_LIBRARY OpenGL::GL)
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        glm
        glad

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        SDL2main
        SDL2-static
        ${OPENGL_LIBRARY}

)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glm
        glad

    PRIVATE
        SDL2main
        SDL2-static
        ${OPENGL_LIBRARY}

)

if( NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    # Copy assets into build directory -- used for non-emscripten builds
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${ASSETS_DIR}/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
endif()