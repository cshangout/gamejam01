cmake_minimum_required(VERSION 3.20)
project(gamejam01)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})

add_subdirectory(engine)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        hangout-engine
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        hangout-engine
)

# Copy assets into build directory
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)